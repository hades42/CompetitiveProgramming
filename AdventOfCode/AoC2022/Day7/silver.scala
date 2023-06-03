import scala.io.Source
import scala.collection.mutable.{Map, ArrayBuffer}

var cache = Map[String, Long]()

def calSum(node: String, 
          childrenMap: Map[String, ArrayBuffer[String]], 
          filesMap: Map[String, Long]): Long = 
{
  filesMap(node) + childrenMap(node).map(calSum(_, childrenMap, filesMap)).sum

  //println(node)
  //if(!cache.contains(node)) {
    //cache(node) = filesMap(node) + childrenMap(node).map(x => filesMap(x) + calSum(x, childrenMap, filesMap)).sum
  //}
  //cache(node)
}

@main def main = {
  /*
  We can have 3 maps: 
  * 1 maps is for maping all the files to the dirs
  * 1 maps is for maping the parent of the dirs
  * 1 maps is for mapping all the children of the dirs
  */
  
  val filesMap = Map[String, Long]()
  // Every node only have 1 parent
  val parentsMap = Map[String, String]()
  // Every node can have multiple children
  val childrenMap = Map[String, ArrayBuffer[String]]()
  
  val input = Source.fromFile("input.txt").getLines.toList
  //println(input)
  var currDir = ""
  for(line <- input){
    if(line.contains("$ cd")){
      val currCmd = line.split(" ").toList 
      if(currCmd(2) != "..") currDir = currCmd(2) 
      else{
        currDir = parentsMap(currDir) 
      }
    }
    else if(line.contains("$ ls")){
      if(!childrenMap.contains(currDir)) childrenMap(currDir) = new ArrayBuffer[String]()
      if(!filesMap.contains(currDir)) filesMap(currDir) = 0 
    }
    else if(!line.contains("$")){
      val currList = line.split(" ").toList
      //println(currList)
      if(currList(0) == "dir"){
        parentsMap(currList(1)) = currDir
        childrenMap(currDir).append(currList(1))
      } else{
        filesMap(currDir) = filesMap(currDir) + currList(0).toLong 
      }
    }
    //println(filesMap)
    //println(parentsMap)
    //println(childrenMap)
    //println("-------------")
  }
  

  
  var result: Long = 0
  for(node <- childrenMap.keys.toList){
    val sum = calSum(node, childrenMap, filesMap)
    if(sum <= 100000){
      result = result + sum
      println(s"${node} ${sum}")
    }
  }

  println("---------------")
  println(filesMap)
  println(parentsMap)
  println(childrenMap)
  println(result)
}
