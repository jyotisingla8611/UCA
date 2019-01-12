
??//InComplete

package Graphs;

import java.util.LinkedList;

public class StrongConnectedComps {
	int v;
	LinkedList<Integer> arr[];

	@SuppressWarnings("unchecked")
	public StrongConnectedComps(int v){
		this.v = v;
		arr = new LinkedList[v];
		for(int i= 0 ;i <v;i++) {
			arr[i] = new LinkedList<>();
		}
	}

	void add(int s, int d) {
		arr[s].add(d);
	}
	
	void dfs(int init,boolean[] visit,int[]in,int time) {
		
	}
	
	void dfs_util(int init) {
		boolean[]visit = new boolean[v];
		int[]in = new int[v];
		int time = 1;
		dfs(init,visit,in,time);
	}
	public static void main(String...args) {
		StrongConnectedComps g = new StrongConnectedComps(7);
		g.add(1, 2);
		g.add(1, 3);
		g.add(2, 3);
		g.add(2, 6);
		g.add(3, 4);
		g.add(3, 5);
		g.add(3, 7);
		g.add(4, 7);
		
	}
}
