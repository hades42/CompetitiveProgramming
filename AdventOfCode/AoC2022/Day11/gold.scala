import scala.io.Source
import scala.collection.mutable.{Map, ArrayBuffer, Stack}

@main def main = {
  val input = Source.fromFile("input.txt").getLines.toList.grouped(7)

  val mapArr = new Array[Map[String, String]](8)
  val worries = new Array[Stack[Long]](8)
  var counts = new Array[Long](8)
  for(i <- 0 to 7){
    mapArr(i) = Map[String, String]()
    worries(i) = new Stack[Long]
  }
  var bigMod: Long = 1
  for(line <- input){
    var index = 0
    line.foreach{
      case s"Monkey $n:" => index = n.toInt 
      case s"  Starting items: $items" => {
        val temp = items.split(", ").toList.map(x => x.toLong)
        temp.foreach(worry => worries(index).push(worry))
      }
      case s"  Operation: new = old $operator $right" => {
        mapArr(index)("operator") = operator
        if(right == "old"){
          mapArr(index)("right") = "-1" 
        } else{
          mapArr(index)("right") = right
        }
      } 
      case s"  Test: divisible by $div" =>{
        mapArr(index)("div") = div
        bigMod = bigMod * div.toInt
      } 
      case s"    If true: throw to monkey $ifTrue" => mapArr(index)("ifTrue") = ifTrue
      case s"    If false: throw to monkey $ifFalse" => mapArr(index)("ifFalse") = ifFalse 
      case _ => 1
    }
  }

  // Loop through 20 rounds
  for(i <- 1 to 10000){
    println("------")
    println(s"Round ${i + 1}")
    // Loop through each monkey 
    for(j <- 0 to 7){
      // loop through each worry 
      while(worries(j).size > 0){
        counts(j) = counts(j) + 1
        val worry = worries(j).pop()
        val right = mapArr(j)("right").toInt.toLong
        val ifTrue = mapArr(j)("ifTrue").toInt
        val ifFalse = mapArr(j)("ifFalse").toInt
        val bored = mapArr(j)("operator") match {
          case "*" => ((worry % bigMod) * ((if(right < 0) worry else right) % bigMod)) % bigMod
          case "+" => ((worry % bigMod) + ((if(right < 0) worry else right) % bigMod)) % bigMod
        } 
        println(s"Monkey: ${j} | worry: ${worry} | right: ${right} | ifTrue: ${ifTrue} | ifFalse: ${ifFalse} | bored: ${bored}")
        if(bored % mapArr(j)("div").toInt == 0){
          worries(ifTrue).push(bored)
        } else{
          worries(ifFalse).push(bored)
        }
      }
    }
    worries.foreach(item => println(item))
    counts.foreach(item => print(s"${item} "))
    println(" ")
  }
  counts = counts.sortWith(_ > _)
  counts.foreach(item => print(s"${item} "))
  val result: Long = counts(0) * counts(1)
  println(result)
  println(bigMod)
}
