package Practice;

/*Program is as : Twisted Prime Number 
that is if both number and its reverse are prime or not*/

/*Input:
2
97
43

Output:
Yes
No*/
import java.util.*;

public class TwistedPrime {
    static int check(int num){
        if(num == 1 || num == 0)
          return 0;
        if(num == 2)
          return 1;
        @SuppressWarnings("unused")
		int flag = 0;
        for(int i = 2 ; i <= num/2 ;i++){
            if(num%i == 0)
               return 0;
        }
        return 1;
    }
	@SuppressWarnings("resource")
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t != 0){
		    int num = sc.nextInt();
		    StringBuffer s = new StringBuffer(String.valueOf(num));
		    s.reverse();
		    int rev = Integer.parseInt(s.toString());
		    num = check(num);
		    rev = check(rev);
		    if(rev == 1 && num == 1)
		    System.out.println("Yes");
		    else
		    System.out.println("No");
		    t--;
		}
	}
}