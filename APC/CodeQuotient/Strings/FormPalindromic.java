/*Input : "mdaam"
Output : "madam" or "amdma"

Input : "abb"
Output : "bab"

Input : "geeksforgeeks"
Output : "No Palindrome"*/

import java.util.*;
public class FormPAlindromic{

     public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        
        //To get frequency of each charactre
        HashMap<Character,Integer>map = new HashMap<Character,Integer>();
        for(int i = 0 ; i < str.length() ;i++){
            if(map.containsKey(str.charAt(i))){
                map.put(str.charAt(i), map.get(str.charAt(i))+1);
            }else{
                map.put(str.charAt(i),1);
            }
        }
        
        String left =""; //To get first half
        String right = ""; //To get second half
        String mid = "";
        int count = 0;
        int flag = 0 ;
        for(Map.Entry x : map.entrySet()){
            Integer freq = (int)x.getValue();
            if(freq%2 == 0){
                while(freq != 0){
                    left = left + x.getKey();
                    right = x.getKey() + right;
                    freq = freq - 2;
                }
            }else{
                if(freq == 1){
                    mid = mid + x.getKey();
                    count++;
                }else{
                    count++;
                }
                if(count > 1){
                    flag = 1;
                    break;
                }
            }
        }
        
        left = left + mid + right;
        if(flag == 1)
          System.out.println("Not Possible");
        else
          System.out.println("The Palindromic string can be written as : \n" + left);
     }
}
