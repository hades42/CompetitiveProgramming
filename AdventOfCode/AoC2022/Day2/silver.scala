import scala.io.Source

@main def main = {
  val lines = Source.fromFile("input.txt").getLines 
  val input: List[(String, String)] = lines.map{
    case s"${elf} ${your}" => (elf, your) 
  }.toList 

  // X -> 1 (Rock)
  // Y -> 2 (Paper)
  // Z -> 3 (Scissors)

  // A (Rock)
  // B (Paper)
  // C (Scissors)

  // Map
  // A -> X  
  // B -> Y  
  // C -> Z  

  // Win map
  // X -> Z
  // Y -> X
  // Z -> Y
  
  // Playing 
  /*
  if map(elf) == your => draw 
  else if map(elf) == winMap(your) => win
  else lose
  */

 val scoreMap = Map("X" -> 1, "Y" -> 2, "Z" -> 3)
 val moveMap = Map("A" -> "X", "B" -> "Y", "C" -> "Z")
 val winMap = Map("X" -> "Z", "Y" -> "X", "Z" -> "Y")
 var scores = 0

 for(game <- input){
   val elf = game._1
   val your = game._2

   if(moveMap(elf) == your){
      // Draw
      scores += scoreMap(your) + 3
   } else if(moveMap(elf) == winMap(your)){
      // Win
      scores += scoreMap(your) + 6
   } else{
     // Lose
      scores+= scoreMap(your)
   }
 }
 println(scores)

}
