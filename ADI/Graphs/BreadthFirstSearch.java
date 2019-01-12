package Graphs;
import java.util.*;

class Graphy{
	int v;
	LinkedList<Integer>arr[];
	
	@SuppressWarnings("unchecked")
	Graphy(int ver){
		v = ver;
		arr = new LinkedList[ver];
		
		for(int i = 0;i<ver;i++) {
			arr[i] = new LinkedList<Integer>();
		}
	}
}
public class BreadthFirstSearch {

	static void add(Graphy g,int src,int des) {
		g.arr[src].add(des);
	}
	
	static void print(Graphy g) {
		for(int i=0;i<g.v;i++) {
			System.out.println("Linked List present at vertex " + i + "is :");
			System.out.print("head");
			for(Integer res : g.arr[i])
				System.out.print("->" + res);
			System.out.println("");
		}
	}
	
	public static void BFS(Graphy g,int strt) {
		boolean []visited = new boolean[g.v];
		
		for(int i=0;i<g.v;i++) {
			visited[i] = false;
		}
		
		Queue<Integer>que = new LinkedList<Integer>();
		visited[strt] = true;
		que.add(strt);
		
		while(que.isEmpty() == false) {
			int s = que.peek();
			System.out.print(s + " ");
			que.remove();
			
			for(int i : g.arr[s]) {
				if(visited[i] == false) {
					visited[i] = true;
					que.add(i);
				}
			}
		}
	}
	
	public static void main(String...args) {
		int ver = 4;
		Graphy graph = new Graphy(ver);
			add(graph,0, 1);
			add(graph,0, 2);
			add(graph,1, 2);
			add(graph,2, 0);
			add(graph,2, 3);
			add(graph,3, 3);
			//print(graph);
		System.out.println("The BFS is as: " );
		BFS(graph,2);
	}
}
