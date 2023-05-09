import scala.io.Source

@main def main = {
  val lines = Source.fromFile("input.txt").getLines 
  val input: List[(String, String)] = lines.map{
    case s"${elf} ${your}" => (elf, your) 
  }.toList 

  // X -> 1 (Rock)
  // Y -> 2 (Paper)
  // Z -> 3 (Scissors)

  // A X (Rock)
  // B Y (Paper)
  // C Z (Scissors)

  // Map
  // A -> X  
  // B -> Y  
  // C -> Z  

  /*
  Y -> Draw 
  X -> Lose
  Z -> Win
  */

 val scoreMap = Map("X" -> 1, "Y" -> 2, "Z" -> 3)
 val moveMap = Map("A" -> "X", "B" -> "Y", "C" -> "Z")
 val loseMap = Map("X" -> "Z", "Y" -> "X", "Z" -> "Y")
 val winMap = Map("X" -> "Y" , "Y" -> "Z", "Z" -> "X")
 var scores = 0

 for(game <- input){
   val elf = game._1
   val your = game._2

   if(your == "Y"){
     // DRAW
     scores = scores + scoreMap(moveMap(elf)) + 3
   } else if(your == "Z"){
     // WIN
     scores = scores + scoreMap(winMap(moveMap(elf))) + 6
   } else{
     scores = scores + scoreMap(loseMap(moveMap(elf)))
   }

 }
 println(scores)

}
