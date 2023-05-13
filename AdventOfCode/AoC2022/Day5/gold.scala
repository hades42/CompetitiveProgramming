import scala.io.Source
import scala.collection.mutable.Stack


val mapStack = collection.mutable.Map[String, Stack[Char]]()

def process(row: List[String], index: Int): Unit = {
  if(row != Nil) {
    val curr = row.head
    if(curr.contains("[")){
      val indexOfBracket = curr.indexOf('[')
      val curCrate = curr.charAt(indexOfBracket + 1)
      mapStack(index.toString).push(curCrate)
    }
    process(row.tail, index + 1)
  }
}

def moveStack(count: String, from: String, to: String) = {
  val tempStack = Stack[Char]()
  for (i <- 1 to count.toInt){
    tempStack.push(mapStack(from).pop)
  }

  for(i <- 1 to count.toInt){
    mapStack(to).push(tempStack.pop) 
  }
}

@main def main = {

  //for(i <- 1 to 9){
    //mapStack(i.toString) = new Stack[Char]() 
  //}

  val input = Source.fromFile("input.txt").mkString.split("\n\n").toList

  val stackThings =  input(0).split("\n").toList.reverse
  val instructions = input(1).split("\n").toList
  val numbers = stackThings.head.split(" ").toList.filter(x => x != "")
  val columns = stackThings.tail.map(x => x.grouped(4).toList)

  for(num <- numbers) {
    mapStack(num.trim()) = new Stack[Char]()
  }
  columns.foreach(x => process(x, 1))
  
  instructions.foreach{line => line match
    case s"move $count from $from to $to" =>
      moveStack(count, from, to)
  }

  println(mapStack)

  for(num <- numbers){
    print(mapStack(num).top)
  }
}
