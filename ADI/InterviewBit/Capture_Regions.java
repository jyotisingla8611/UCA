/*Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X*/

package InterviewBit;
import java.util.*;
public class Capture_Regions{
    
    static void island(boolean[][]visit,int i,int j,char[][]ar){
    if(i < 0 || i>= ar.length)
    return;
    if(j < 0 || j >= ar.length)
    return;
    if(ar[i][j] != '0')
     return;
    if(visit[i][j] == true)
     return;
     
    visit[i][j] = true;
    ar[i][j] = 'A';
    island(visit,i,j+1,ar);
    island(visit,i,j-1,ar);
    island(visit,i-1,j,ar);
    island(visit,i+1,j,ar);
}

static void isSafe(ArrayList<ArrayList<Character>>a){
    char[][]arr = new char[a.size()][];
    
    for(int i = 0 ; i < a.size() ; i++){
        arr[i] = new char[a.get(i).size()];
        for(int j = 0; j < a.get(i).size(); j++){
            arr[i][j] = a.get(i).get(j);
        }
    }
    
    boolean[][] visit = new boolean[a.size()][a.size()];
    for(int i = 0 ; i < a.size() ; i++){
        int cols = a.get(i).size();
        for(int j = 0 ; j < a.get(i).size() ; j++){
            if(i == 0 || i == a.size()-1 || j == 0 || j == cols-1){
                if(arr[i][j] == '0'){
                island(visit,i,j,arr);
                }
            } 
        }
    }
    
    for(int i =0 ;i < a.size();i++){
        for(int j = 0 ; j< a.get(i).size();j++){
            if(arr[i][j] == '0'){
                a.get(i).set(j,'X');
            }
        }
    }
    
    for(int i = 0;i<a.size();i++){
        for(int j = 0 ; j < a.get(i).size();j++){
            if(arr[i][j] == 'A')
               a.get(i).set(j,'0');
        }
    }
}
     public static void main(String...args){
         ArrayList<Character> a1 = new ArrayList<Character>(); 
         a1.add('X'); 
         a1.add('X');
         a1.add('X'); 
         a1.add('X');
         ArrayList<Character> a2 = new ArrayList<Character>(); 
         a2.add('X'); 
         a2.add('0');
         a2.add('0'); 
         a2.add('X');
         ArrayList<Character> a3 = new ArrayList<Character>(); 
         a3.add('X'); 
         a3.add('X');
         a3.add('0'); 
         a3.add('X');
         ArrayList<Character> a4 = new ArrayList<Character>(); 
         a4.add('X'); 
         a4.add('0');
         a4.add('X'); 
         a4.add('X');
         ArrayList<ArrayList<Character>>ar = new ArrayList<ArrayList<Character>>();
         ar.add(a1);
         ar.add(a2);
         ar.add(a3);
         ar.add(a4);
         
         isSafe(ar);
         
         for(int i = 0; i<ar.size();i++){
             for(int j = 0 ; j< ar.get(i).size();j++){
                 System.out.print(ar.get(i).get(j) + " ");
             }
             System.out.println("");
         }
     }
}
