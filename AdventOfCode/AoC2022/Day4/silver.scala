import scala.io.Source

def check(a: Int, b: Int, c: Int, d: Int) = {
  //if(c <= a && c <= b && d >= b) true else false 
  if(c <= a && a <= d) true else false 
}

/*
check(2, 8, 3 , 7)
check(3, 7, 2, 8)
2 <= 3 && 2 <= 7 && 8 >= 7
*/

def eval(pair: List[String]) = {
  val first = pair(0).split("-").toList
  val (a, b) = (first(0).toInt, first(1).toInt)
  val second = pair(1).split("-").toList
  val (c, d) = (second(0).toInt, second(1).toInt)
  //println(s"a: $a, b: $b, c: $c, d: $d")
  //println(check(a, b, c, d))
  //println(check(c, d, a, b))
  check(a, b, c, d) || check(c, d, a, b)
}

def process(input: List[List[String]], count: Int): Int = {
  if(input !=  Nil){
    //println(count)
    val check = eval(input.head)
    if(check){
      Math.max(count, process(input.tail, count + 1))
    } else{
      Math.max(count, process(input.tail, count))
    }
  } else count
}

@main def main = {
  /*
  a - b 
  c - d

  To check for 1 range belong to the other

  Let's assume in this case range a - b is covered by range c - d 

  c <= a && c <= b && d >= b 
  */

 val input = Source.fromFile("input.txt").getLines.toList.map(str => str.split(",").toList)
 val result = process(input, 0)
 println("==========")
 println(result)
}
