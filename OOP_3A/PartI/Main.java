import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        System.out.println("input 1:push,2:pop,3:isempty,-1:shut down : ");
        Scanner scan = new Scanner(System.in);
        Stack newStack = new Stack();
        int station = scan.nextInt();
        while (station != -1) {
            if (station == 1) {
                System.out.println("please input item to push : ");
                int item = scan.nextInt();
                newStack.push(item);
            } else if (station == 2) {
                int item = newStack.pop();
                if (item != Integer.MIN_VALUE)
                    System.out.println("[" + item + "]" + "has already popped out");
            } else if (station == 3) {
                newStack.empty();
            }  else {
                System.out.println("your input is wrong.");
            }
            System.out.println("input 1:push,2:pop,3:isempty,-1:shut down : ");
            station = scan.nextInt();
        }
        System.out.println("the program shut down.");
        System.exit(0);
    }
}
