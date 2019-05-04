//To find the Dictionary rank of a word having NON_REPEATED alphabets
package Practice;
import java.util.*;
public class wordRank{

     static int fact(int n){
         int f = 1;
         while(n > 1){
             f = f *n;
             n--;
         }
         return f;
     }
     static int min_count(int i,int n,int k,int []a){
         int cnt = 0;
         for(int j = i ;j < n ;j++){
             if(a[j] < k)
               cnt++;
         }
         return cnt;
         
     }
     public static void main(String []args){
        String str = "take";
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        int sum = 1;
        String temp = new String(arr);
        int len = str.length();
        System.out.println("Sorted String is as : ");
        System.out.println(temp);
        int[]array = new int[len];
        for(int i = 0 ; i < len ; i++){
            array[i] = temp.indexOf(str.charAt(i))+1;
        }
        System.out.println("Location of alphabet in order : ");
        for(int i = 0 ; i < len ; i++){
            System.out.print(array[i]);
        }
        System.out.println("");
        for(int i = 0 ;i < len-1 ; i++){
            array[i] = min_count(i+1,len,array[i],array);

        }
        array[len-1] = 0;
        System.out.println("Number of smaller digits : ");
        for(int i = 0 ; i < len ; i++){
            System.out.print(array[i]);
        }
        System.out.println("");
        int r = len-1;
        for(int i = 0 ; i < len ;i++){
            sum = sum + array[i] * fact(r--);
        }
        System.out.println("Rank is as : ");
        System.out.print(sum);
     }
}













//Another Method
/*import java.util.*;
public class HelloWorld{

     static int fact(int n){
         int f = 1;
         while(n > 1){
             f = f * n;
             n--;
         }
         return f;
     }
     static int min_count(String s){
         int cnt = 0;
         for(int j = 0 ;j < s.length() ;j++){
             if(s.charAt(j) != '$')
               cnt++;
         }
         return cnt;
         
     }
     public static void main(String []args){
        String str = "take";
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        int sum = 1;
        String temp = new String(arr);
        int len = str.length();
        System.out.println(temp);
        for(int i = 0 ; i < len  ;i++){
            for(int j = 0 ; j < len ;j++){
                if(str.charAt(i) == temp.charAt(j)){
                    temp = temp.replace(str.charAt(i),'$');
                    break;
                }else if(temp.charAt(j)!='$'){
                    int x = min_count(temp);
                    System.out.print(x + " x");
                    sum = sum + fact(x-1);
                }
            }
            
        }
        System.out.print(sum);
     }
}*/
