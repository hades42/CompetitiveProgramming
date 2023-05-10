import scala.io.Source

def cal(x: Char): Int = {
  val temp = x.toInt - 96
  if(temp < 0) temp + 58 else temp
}

def eval(s1: String, s2: String, s3: String): Int = {
  s1.map(c => if(s2.indexOf(c) != -1 && s3.indexOf(c) != -1) cal(c) else 0).max
}


@main def main = {
  val lines: List[String] = Source.fromFile("input.txt").getLines.toList
  val test = lines.grouped(3).toList.map{
    x => eval(x(0), x(1), x(2))
  }
  println(test.sum)
}
