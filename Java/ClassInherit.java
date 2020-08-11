class ClassInherit{
    public static void main(String args[]){
        Super instance = new Sub();
        instance.dispName();
    }
}

class Super{
    public void dispName(){
        System.out.println("This is an instance of Super class");
    }
}

class Sub extends Super{
    public void dispName(){
        System.out.println("This is an instance of Sub class.");
        this.showExtra();
    }

    public void showExtra(){
        System.out.println("Created by me.");
    }
}

