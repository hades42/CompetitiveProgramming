import scala.io.Source
import scala.collection.mutable.ListBuffer

@main def main = {
  val lines = Source.fromFile("input.txt").getLines
  var finalSum = 0
  var tempSum = 0
  for(line <- lines){
    if(line.isEmpty){
      if(tempSum > finalSum){
        finalSum = tempSum
      }
      tempSum = 0
    } else{
      tempSum += line.toInt
    }
  }

  print(finalSum)
}
