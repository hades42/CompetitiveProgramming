import scala.io.Source

def compute(num: Int) = {
  if(num > 0) 1 else 0
}

@main def main = {
  val input = Source.fromFile("input.txt").getLines.toList
  var sum = 0
  input.foreach{
    case s"$dir $number" => {
      sum = sum + number.toInt
    }
  }
  val arr = Array.ofDim[Int](sum, sum)
  var hR = (sum - 1)/2
  var hC = (sum - 1)/2
  var tR = hR 
  var tC = hC
  arr(tR)(tC) = 1
  println(sum)
  input.foreach{
    case s"$dir $number" => {
      val step = number.toInt

      for(i <- 1 to step){
        if(dir == "U"){
          hR = hR - 1
        } else if(dir == "D"){
          hR = hR + 1 
        } else if(dir == "R"){
          hC = hC + 1
        } else if(dir == "L"){
          hC = hC - 1
        }

        // If H and T on the same row
        if(tR == hR){
          // Check for the column
          if(Math.abs(hC - tC) > 1){
            if(hC > tC) tC = tC + 1 
            else tC = tC - 1 
          }
        } else if(tC == hC){
          // If H and T on the same column 
          if(Math.abs(hR - tR) > 1){
            if(hR > tR) tR = tR + 1
            else tR = tR - 1
          }
        } else {
          // If H and T are not even on the same row or column (diagonal)
          if(Math.abs(hC - tC) > 1 || Math.abs(hR - tR) > 1){
            if(hC > tC && hR > tR) {
              tC = tC + 1
              tR = tR + 1
            } else if(hC > tC && hR < tR){
              tC = tC + 1
              tR = tR - 1
            } else if(hC < tC && hR > tR){
              tC = tC - 1
              tR = tR + 1
            } else{
              tC = tC - 1
              tR = tR - 1
            }
          }
        }

        arr(tR)(tC) = arr(tR)(tC) + 1
      }
    }
  }

  //arr.foreach(row => println(row.mkString(" ")))
  var res = 0
  arr.foreach(row => row.foreach(el => {
    if(el > 0) res = res + 1
  }))
  println(res)
}
