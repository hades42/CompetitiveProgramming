import scala.io.Source

//val arr = new Array[Char](242)
val arr = Array.fill[Char](242)('.')

def compute(cycle: Int, Xvalue: Int): Unit= {
  val sprite = (Xvalue to Xvalue + 2).toList
  println(s"Sprite: ${sprite} | CTR: $cycle")
  if(cycle >= 41 && cycle <= 80){
    if(sprite.contains(cycle - 40)){
      arr(cycle) = '#'
    }
  } else if(cycle >= 81 && cycle <= 120){
    if(sprite.contains(cycle - 80)){
      arr(cycle) = '#'
    }
  } else if(cycle >= 121 && cycle <= 160){
    if(sprite.contains(cycle - 120)){
      arr(cycle) = '#'
    }
  } else if(cycle >= 161 && cycle <= 200){
    if(sprite.contains(cycle - 160)){
      arr(cycle) = '#'
    }
  } else if(cycle >= 201 && cycle <= 240 ){
    if(sprite.contains(cycle - 200)){
      arr(cycle) = '#'
    }
  } else {
    if(sprite.contains(cycle)){
      arr(cycle) = '#' 
    }
  }
}

@main def main = {
  val input = Source.fromFile("input.txt").getLines.toList
  var cycle = 0
  var Xvalue = 1
  val test = 1 to 3
  input.foreach{
    case s"$inst $value" => {
      cycle = cycle + 1
      compute(cycle, Xvalue)
      cycle = cycle + 1
      compute(cycle, Xvalue)
      Xvalue = Xvalue + value.toInt
    }
    case s"noop" => {
      cycle = cycle + 1
      compute(cycle, Xvalue)
    }
  }

  var count = 0
  for(i <- 1 to 241){
    print(arr(i))
    count = count + 1
    if(count == 40){
      count = 0
      println(" ")
    }
  }
}
