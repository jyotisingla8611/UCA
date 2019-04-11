package InterviewBit;
import java.util.*;
class cords{
	int x;
	int y;
	cords(int x,int y){
		this.x = x;
		this.y = y;
	}
}

public class ValidPath {
	public static void main(String...args) {
		 
	}
	@SuppressWarnings("unused")
	private static boolean isSafe(int rows, int cols, boolean[][] visit, int i, int j) {
		return (i>=0 && i<rows && j>=0 && j<cols && !visit[i][j]);
	}
	
	public String solve(int A,int B,int C,int D,ArrayList<Integer>E,ArrayList<Integer>F) {
		return "";
	}
}
