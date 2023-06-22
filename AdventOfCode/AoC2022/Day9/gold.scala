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
  val knotSize = 10
  val arr = Array.ofDim[Int](sum, sum)
  var hR = (sum - 1)/2
  var hC = (sum - 1)/2
  var tR = hR 
  var tC = hC
  var allRow = new Array[Int](knotSize)
  var allColumn = new Array[Int](knotSize)
  for(i <- 0 to knotSize - 1){
    allRow(i) = hR
    allColumn(i) = hC
  }

  arr(allRow(knotSize - 1))(allColumn(knotSize - 1)) = 1
  input.foreach{
    case s"$dir $number" => {
      val step = number.toInt
      for(i <- 1 to step){
        if(dir == "U"){
          allRow(0) = allRow(0) - 1
        } else if(dir == "D"){
          allRow(0) = allRow(0) + 1 
        } else if(dir == "R"){
          allColumn(0) = allColumn(0) + 1
        } else if(dir == "L"){
          allColumn(0) = allColumn(0) - 1
        }
        for(k <- 0 to knotSize - 1){
          if(k != knotSize - 1){
            // If H and T on the same row
            if(allRow(k+1) == allRow(k)){
              // Check for the column
              if(Math.abs(allColumn(k) - allColumn(k+1)) > 1){
                if(allColumn(k) > allColumn(k+1)) allColumn(k+1) = allColumn(k+1) + 1 
                else allColumn(k+1) = allColumn(k+1) - 1 
              }
            } else if(allColumn(k+1) == allColumn(k)){
              // If H and T on the same column 
              if(Math.abs(allRow(k) - allRow(k+1)) > 1){
                if(allRow(k) > allRow(k+1)) allRow(k+1) = allRow(k+1) + 1
                else allRow(k+1) = allRow(k+1) - 1
              }
            } else {
              // If H and T are not even on the same row or column (diagonal)
              if(Math.abs(allColumn(k) - allColumn(k+1)) > 1 || Math.abs(allRow(k) - allRow(k+1)) > 1){
                if(allColumn(k) > allColumn(k+1) && allRow(k) > allRow(k+1)) {
                  allColumn(k+1) = allColumn(k+1) + 1
                  allRow(k+1) = allRow(k+1) + 1
                } else if(allColumn(k) > allColumn(k+1) && allRow(k) < allRow(k+1)){
                  allColumn(k+1) = allColumn(k+1) + 1
                  allRow(k+1) = allRow(k+1) - 1
                } else if(allColumn(k) < allColumn(k+1) && allRow(k) > allRow(k+1)){
                  allColumn(k+1) = allColumn(k+1) - 1
                  allRow(k+1) = allRow(k+1) + 1
                } else{
                  allColumn(k+1) = allColumn(k+1) - 1
                  allRow(k+1) = allRow(k+1) - 1
                }
              }
            }
            //println(s"dir: ${dir}| step: ${i} | k: ${k} | ${allRow(k)} ${allColumn(k)} | ${allRow(k+1)} ${allColumn(k+1)}")
            if(k + 1 == knotSize - 1){
              //println(s"dir: ${dir}| step: ${i} | k: ${k+1} | ${allRow(k+1)} ${allColumn(k+1)}")
              arr(allRow(k+1))(allColumn(k+1)) = arr(allRow(k+1))(allColumn(k+1)) + 1
            }
          }
        }
      }
    }
  }

  //arr.foreach(row => println(row.mkString(" ")))
  //println(allRow.mkString(" "))
  //println(allColumn.mkString(" "))
  var res = 0
  arr.foreach(row => row.foreach(el => {
    if(el > 0) res = res + 1
  }))
  println(res)
}
