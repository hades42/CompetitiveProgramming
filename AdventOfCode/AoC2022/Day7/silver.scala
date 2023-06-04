import scala.io.Source
import scala.collection.mutable.{Map}

import TerminalOutput.*
import Command.*


enum Command:
  case ChangeDirectory(directory: String)
  case ListFiles

enum TerminalOutput:
  case Cmd(cmd: Command)
  case Directory(name: String)
  case File(size: Int, name: String)

class DirectoryStructure(val name: String,
                         val subDirectories: Map[String, DirectoryStructure],
                         val files: Map[String, Int],
                         val parent: DirectoryStructure | Null)

def buildState(input: List[TerminalOutput], currDirectory: DirectoryStructure | Null, rootDir: DirectoryStructure): Unit = input match{
  case Cmd(ChangeDirectory("/")) :: t => buildState(t, rootDir, rootDir)
  case Cmd(ChangeDirectory("..")) :: t => buildState(t, currDirectory.parent, rootDir)
  case Cmd(ChangeDirectory(name)) :: t => buildState(t, currDirectory.subDirectories(name), rootDir)
  case Cmd(ListFiles) :: t => buildState(t, currDirectory, rootDir)
  case File(size, name) :: t => 
    currDirectory.files.put(name, size)
    buildState(t, currDirectory, rootDir)
  case Directory(dir) :: t =>
    currDirectory.subDirectories.put(dir, new DirectoryStructure(dir, Map.empty, Map.empty, currDirectory))
    buildState(t, currDirectory, rootDir)
  case Nil => ()
} 

def buildData(input: List[TerminalOutput]) =
  val rootDir = new DirectoryStructure("/", Map.empty, Map.empty, null)
  buildState(input, null, rootDir)
  rootDir

def parse(str: List[String]) = str.map{
  case s"$$ cd $directory" => Cmd(ChangeDirectory(directory))
  case s"$$ ls" => Cmd(ListFiles)
  case s"dir $directory" => Directory(directory)
  case s"$size $file" => File(size.toInt, file)
}.toList

def directorySize(curr: DirectoryStructure): Int = {
  curr.files.values.sum + curr.subDirectories.values.map(directorySize).sum
}

def collectSizes(init: DirectoryStructure, demand: Int => Boolean): Iterable[Int] = {
  val currSize = directorySize(init)
  val children = init.subDirectories.values.flatMap(collectSizes(_, demand))
  if(demand(currSize)) then currSize :: children.toList else children
}

@main def main = {
  //println(Source.fromFile("input.txt").toLIst)
  val input = parse(Source.fromFile("input.txt").getLines.toList)
  val root1 = buildData(input)
  println(collectSizes(root1, _ < 100000).sum) 
}
