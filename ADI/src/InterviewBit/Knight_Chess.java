/*Input:

N, M, x1, y1, x2, y2
where N and M are size of chess board
x1, y1  coordinates of source point
x2, y2  coordinates of destination point
Output:

return Minimum moves or -1
Example

Input : 8 8 1 1 8 8
Output :  6*/

package InterviewBit;
import java.util.*;
class cord{
	int x;
	int y;
	cord(int x,int y){
		this.x = x;
		this.y = y;
	}
}
public class Knight_Chess {
	
	public static void main(String...args) {
		int res = knight(8,8,1,1,8,8);
		System.out.println("Minimum Moves are as : " + res);
	}
	private static boolean isSafe(int rows, int cols, boolean[][] visit, int i, int j) {
		return (i>=0 && i<rows && j>=0 && j<cols && !visit[i][j]);
	}
	
	public static int knight(int A,int B,int C,int D,int E,int F) {
		Queue<cord>que = new LinkedList<cord>();
		int rn[] = {-1,-1,1,1,-2,2,-2,2};
		int cn[] = {-2,2,-2,2,-1,-1,1,1};
		int rows = A;
		int cols = B;
		int srcx = C - 1;
		int srcy = D - 1;
		int desx = E - 1;
		int desy = F - 1;
		if(srcx == desx && srcy == desy)
			return 0;
		boolean[][] visit = new boolean[rows][cols];
		cord source = new cord(srcx,srcy);
		cord dest = new cord(desx,desy);
		int count = 1 ;
		que.add(source);
		que.add(new cord(-1,-1));
		visit[srcx][srcy] = true;
		while(que.size() != 0) {
			cord temp = que.poll();
			if(temp.x != -1 || temp.y != -1) {
			for(int i = 0; i < 8 ; i++) {
				if(isSafe(rows,cols,visit,temp.x+rn[i],temp.y+cn[i])) {
					if(temp.x+rn[i]==dest.x && temp.y+cn[i]==dest.y)
						return count;
					visit[temp.x+rn[i]][temp.y+cn[i]] = true;
					que.add(new cord(temp.x+rn[i],temp.y+cn[i]));
				}
			}
		   }else {
			   que.add(new cord(-1,-1));
			   count++;
			   cord temp1 = que.peek();
			   if(temp1.x == -1 && temp1.y == -1)
				   break;
		   }
		}
		return -1;
	}
}
