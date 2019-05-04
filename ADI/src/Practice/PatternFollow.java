/*Input
5
D
I
DD
IIDDD
DDIDDIID

Note : Here I means Increasing and D means Decreasing

Output
21
12
321
126543
321654798*/
package Practice;
import java.util.*;

public  class PatternFollow {
    static void findPattern(String s){
	Stack<Integer>st = new Stack<Integer>();
	for(int i=0;i<=s.length();i++){
		st.push(i+1); 
		if(s.length()==i || s.charAt(i)=='I' ){ 
			while(!st.empty()){ 
				System.out.print(st.peek());
				st.pop();
			}
		}
	}
	System.out.println("");
}
	@SuppressWarnings("resource")
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t != 0 ){
		    String s =sc.next();
		    findPattern(s);
		    t--;
		}
	}
}