data class User(val name: String, val point: Int=0);

fun printUsers(users: List<User>){
    users.forEach{user->
        print("${user.name} : ${user.point} \n");
    }
}

fun main(args:Array<String>){
    val people = listOf(User("Tarou", 100), User("Hanako"), User("Jiro", 50));
    printUsers(people);
}