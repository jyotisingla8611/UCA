/*Sample Input

10
1 97 // PUSH
2  // POP
1 20
2
1 26
1 20
2
3 //Print Maximum Element Till
1 91
3
Sample Output

26
91*/
package Stacks;
import java.util.*;

public class MaximumElement {

    public static void main(String[] args) {
        Stack<Integer>stk = new Stack<Integer>();
        //this stack is used to maintain only maximum elements till
        Stack<Integer>stk1 = new Stack<Integer>();
        @SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        while(num != 0){
            int op = sc.nextInt();
            if(op == 1){
                int n = sc.nextInt();
                stk.push(n);
                if (stk1.isEmpty() || n >= stk1.peek()) {
                        stk1.push(n);
                }
            }else if(op == 2){
                int x = stk.pop();
                if(stk1.peek() == x)
                  stk1.pop();
            }else {
                System.out.println(stk1.peek());
            }
            num--;
        }
    }
}

