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
  // check left
  //println("check left")
  //leftToRight.foreach(row => println(row.mkString(" ")))

  for(i <- 0 to rows - 1){
    for(j <- (columns - 1) to 0 by -1){
      if(j == (columns - 1)) rightToLeft(i)(j) = forest(i)(j)
      else{
        if(forest(i)(j) < rightToLeft(i)(j + 1)){
          rightToLeft(i)(j) = rightToLeft(i)(j + 1)
        } else{
          rightToLeft(i)(j) = forest(i)(j)
        }
      }
    }
  }

   //check right
   //println("check right")
  //rightToLeft.foreach(row => println(row.mkString(" ")))

  for(j <- 0 to columns - 1){
    for(i <- 0 to rows - 1){
      if(i == 0) topToBottom(i)(j) = forest(i)(j) 
      else {
        if(forest(i)(j) < topToBottom(i - 1)(j)){
          topToBottom(i)(j) = topToBottom(i - 1)(j)
        } else{
          topToBottom(i)(j) = forest(i)(j)
        }
      }
    }
  }

  // check top
  //println("check top")
  //topToBottom.foreach(row => println(row.mkString(" ")))

  for(j <- 0 to columns - 1){
    for(i <- rows - 1 to 0 by -1){
      if(i == (rows - 1)) bottomToTop(i)(j) = forest(i)(j)
      else{
        if(forest(i)(j) < bottomToTop(i + 1)(j)){
          bottomToTop(i)(j) = bottomToTop(i + 1)(j)
        } else{
          bottomToTop(i)(j) = forest(i)(j) 
        }
      }
    }
  }

  // check bottom
  //println("check bottom")
  //bottomToTop.foreach(row => println(row.mkString(" ")))

  var count = 0
  for(i <- 1 to rows - 2) {
    for(j <- 1 to columns -2) {
      // check left
      if(forest(i)(j) > leftToRight(i)(j-1)){
        count = count + 1
      } else if(forest(i)(j) > rightToLeft(i)(j + 1)){
        count = count + 1
      } else if(forest(i)(j) > topToBottom(i - 1)(j)){
        count = count + 1
      } else if(forest(i)(j) > bottomToTop(i + 1)(j)){
        count = count + 1
      }
    }
  }
  count = count + (rows * 2 + columns * 2 - 4)
  println(count)
}

