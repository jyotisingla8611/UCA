package Graphs;

import java.util.LinkedList;

class Graphys{
	int v;
	LinkedList<Integer>arr[];
	
	@SuppressWarnings("unchecked")
	Graphys(int v){
		this.v = v;
		arr = new LinkedList[v];
		
		for(int i=0;i<v;i++) {
			arr[i] = new LinkedList<>();
		}
	}
}
public class DepthFirstSearch {

	static void add(Graphys g,int s,int d) {
		g.arr[s].add(d);
		g.arr[d].add(s);
	}
	static void print(Graphys g) {
		for(int i=0;i<g.v;i++) {
			System.out.println("Linked List present at vertex " + i + "is :");
			System.out.print("head");
			for(Integer res : g.arr[i])
				System.out.print("->" + res);
			System.out.println("");
		}
	}
	static void dfs(Graphys g,boolean []res,int v) {
		
		res[v] = true;
		
			System.out.print(v + " ");
		
		for(int i=0;i<g.arr[v].size();i++) {
			int x = g.arr[v].get(i);
			if(!res[x])
				continue;
			dfs(g,res,x);
		}
		//res[v] = true;
	}
	public static void main(String[] args) {
		Graphys g = new Graphys(4); 
        add(g, 0, 1); 
        add(g, 0, 2); 
        add(g, 1, 2); 
        add(g, 2, 0); 
        add(g, 2, 3); 
        add(g, 3, 3); 
        print(g);
        boolean []res = new boolean[g.v];
        dfs(g,res,2);
	}

}
