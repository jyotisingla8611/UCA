/*Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more 
adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X*/
package InterviewBit;

import java.util.ArrayList;

public class BlackShapes {
	
	static  void dfs(boolean[][]visit,int i,int j,ArrayList<String>A){
        if(i<0 || i>= A.size())
            return ;
        if(j<0 || j>=A.get(0).length())
            return;
        if(A.get(i).charAt(j) != 'X')
            return ;
        if(visit[i][j] == true)
            return;
        visit[i][j] = true;
        dfs(visit,i,j+1,A);
        dfs(visit,i, j-1,A);
        dfs(visit,i+1, j,A);
        dfs(visit,i-1, j,A);
    }
    public static int black(ArrayList<String> A) {
        boolean[][]visit = new boolean[A.size()][A.get(0).length()];
    int count = 0 ;
    for(int i = 0; i < A.size() ;i++){
        for(int j = 0; j < A.get(i).length();j++){
            if(A.get(i).charAt(j) == 'X' && visit[i][j] == false){
                dfs(visit,i,j,A);
                count++;
            }
        }
    }
    return count;
    }
    public static void main(String...args){
        int count;
        ArrayList<String>arr = new ArrayList<String>();
        arr.add("OOOXOOO");
        arr.add("OOXXOXO");
        arr.add("OXOOOXO");
        count =  black(arr);
        System.out.println("Count is as : " + count);
    }

}
