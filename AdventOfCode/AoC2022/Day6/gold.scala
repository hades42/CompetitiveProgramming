import scala.io.Source
import scala.collection.mutable.Map

@main def main = {
  val map = Map[Char, Int]()
  val input = Source.fromFile("input.txt").getLines.toArray
  val arr = input(0)
  var limit = 14
  var count = 14
  
  for(init <- 1 to limit){
    if(map.contains(arr(init - 1))){
      map(arr(init - 1)) = map(arr(init - 1)) + 1
    } else map(arr(init - 1)) = 1 
  }
  
  if(map.size == limit){
    println(count)
  } else{
    for(i <- limit to arr.size - 1){
      if(map.size < limit){
        if(map.contains(arr(i))){
          map(arr(i)) = map(arr(i)) + 1
        } else {
          map(arr(i)) = 1
        }
        
        map(arr(i-limit)) = map(arr(i-limit)) - 1
        if(map(arr(i - limit)) == 0) map.remove(arr(i - limit))

        count = count + 1
      }
    }
  }

  println(count)
}
