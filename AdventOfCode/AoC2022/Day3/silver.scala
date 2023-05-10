import scala.io.Source


def process(first: Set[Char], second: List[Char]): Int = {
  if(first(second.head)) {
    val score = (second.head).toInt - 96
    // 26 for all the lower case
    // 32 is the difference between lower case and uppercase in ascii code
    // 26 + 32 = 58
    if (score < 0) score + 58 else score
  } else {
    process(first, second.tail)
  }
}


@main def main = {
  val lines = Source.fromFile("input.txt").getLines
  var result = 0
  for(line <- lines){
    val len = line.length
    val first = line.slice(0, len/2 - 1).toSet
    val second = line.slice(len/2, len).toList
    println(line.slice(0, len/2 - 1))
    println(line.slice(len/2, len))
    println("=========")
    //println(process(first, second))
    //println(first)
    //println(second)
    result = result + process(first, second)
  }
  print(result)
}
