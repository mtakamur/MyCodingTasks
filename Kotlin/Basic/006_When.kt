fun main(){
    val value : Int = 20;
    
    when(value){
        in 0 .. 50 -> {
            println("poor.");
        }
        in 10 .. 50 -> {
            println("bad");
        }
        in 50 .. 80 -> {
            println("not good")
        }
        in 80 .. 100 -> {
            println("good");
        }
    }
}


