import scala.io.Source
import scala.collection.mutable.ListBuffer

def getCalories(lines: Iterator[String]): List[Int] = {
  val caloriesList = List.newBuilder[Int]
  var tempSum = 0
  for (line <- lines) {
    if(line.isEmpty){
      caloriesList += tempSum 
      tempSum = 0
    } else{
      tempSum += line.toInt
    }
  }
  caloriesList.result()
}

def gold(lines: Iterator[String]): List[Int] = {
  getMaxBy3(getCalories(lines))  
}

def getMaxBy3(calories: List[Int]): List[Int]  = {
  calories.sortWith(_ > _).take(3)
}


@main def main = {
  val lines = Source.fromFile("input.txt").getLines
  val sum = gold(lines).sum
  print(sum)
}
