import scala.io.Source

def compute(cycle: Int, curValue: Int): Int = {
  if(cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
  {
    println(s"${cycle}: ${curValue}")
    cycle * curValue
  } else {
    0
  }
}

@main def main = {
  val input = Source.fromFile("input.txt").getLines.toList
  var cycle = 0
  var res = 0
  var curValue = 1
  input.foreach{
    case s"$inst $value" => {
      cycle = cycle + 1
      res = res + compute(cycle, curValue)
      cycle = cycle + 1
      res = res + compute(cycle, curValue)
      curValue = curValue + value.toInt
    }
    case s"noop" => {
      cycle = cycle + 1
      res = res + compute(cycle, curValue)
    }
  }
  println(res)
}
