import scala.io.Source

def rotateArray(matrix: Array[Array[Int]]): Array[Array[Int]] = {
  val numRows = matrix.length
  val numCols = matrix(0).length

  val rotatedMatrix = Array.ofDim[Int](numCols, numRows)

  for (i <- 0 until numRows) {
    for (j <- 0 until numCols) {
      rotatedMatrix(j)(numRows - i - 1) = matrix(i)(j)
    }
  }

  rotatedMatrix
}

def flipArrayLeftToRight(matrix: Array[Array[Int]]): Array[Array[Int]] = {
  val numRows = matrix.length
  val numCols = matrix(0).length

  val flippedMatrix = Array.ofDim[Int](numRows, numCols)

  for (i <- 0 until numRows) {
    for (j <- 0 until numCols) {
      flippedMatrix(i)(numCols - j - 1) = matrix(i)(j)
    }
  }

  flippedMatrix
}

def compute(numbers: Array[Int], cond: Int): Int = {
  var count = 0
  numbers.foreach { num =>
    if (num < cond) {
      count += 1
    } else {
      count += 1
      return count
    }
  }
  return count
}

@main def main = {
  val input = Source.fromFile("input.txt").getLines.toList
  val rows = input.size
  val columns = input(0).toList.size

  val forest = Array.ofDim[Int](rows, columns)
  
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


  val rotatedArr = flipArrayLeftToRight(rotateArray(forest))
  rotatedArr.foreach(row => println(row.mkString(" ")))

  var res = 0
  for(row <- 1 to rows - 2) {
    for(col <- 1 to columns -2) {
      // check left 
      val left = forest(row).slice(0, col).reverse
      println(s"${forest(row)(col)}")
      println(s"left: ${left.mkString(" ")}")
      println(compute(left, forest(row)(col)))
      val cLeft = compute(left, forest(row)(col))

      // check right
      val right = forest(row).slice(col + 1, columns)
      println(s"right: ${right.mkString(" ")}")
      println(compute(right, forest(row)(col)))
      val cRight = compute(right, forest(row)(col))

      // check top
      val top= rotatedArr(col).slice(0, row).reverse
      println(s"top: ${top.mkString(" ")}")
      println(compute(top, forest(row)(col)))
      val cTop = compute(top, forest(row)(col)) 

      // check bottom 
      val bottom= rotatedArr(col).slice(row + 1, columns)
      println(s"bottom: ${bottom.mkString(" ")}")
      println(compute(bottom, forest(row)(col)))
      val cBottom = compute(bottom, forest(row)(col)) 
      println("===========")

      val temp = cLeft * cBottom * cTop * cRight
      res = Math.max(temp, res)
    }
  }

  println(res)
}

