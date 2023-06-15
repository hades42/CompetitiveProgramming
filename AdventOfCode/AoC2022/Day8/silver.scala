import scala.io.Source

@main def main = {
  val input = Source.fromFile("input.txt").getLines.toList
  val rows = input.size
  val columns = input(0).toList.size

  val forest = Array.ofDim[Int](rows, columns)
  val leftToRight = Array.ofDim[Int](rows, columns)
  val rightToLeft = Array.ofDim[Int](rows, columns)
  val topToBottom = Array.ofDim[Int](rows, columns)
  val bottomToTop = Array.ofDim[Int](rows, columns)
  
  var i = 0
  for(line <- input) {
    val trees = line.toList
    var j = 0 
    for(tree <- trees){
      forest(i)(j) = tree - '0'
      j = j + 1
    }
    i = i + 1
  }

  //leftToRight.foreach(row => println(row.mkString(" ")))
  for(i <- 0 to rows - 1){
    for(j <- 0 to columns - 1){
      if(j == 0) leftToRight(i)(j) = forest(i)(j)
      else {
        if(forest(i)(j) < leftToRight(i)(j- 1)){
          leftToRight(i)(j) = leftToRight(i)(j- 1)
        } else{
          leftToRight(i)(j) = forest(i)(j)
        }
      }
    }
  }

  leftToRight.foreach(row => println(row.mkString(" ")))
}

