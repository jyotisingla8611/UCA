//Undirected Graph
import java.util.LinkedList;
import java.util.Scanner;

class Graph{
	int v;
	LinkedList<Integer>arr[];
	
	@SuppressWarnings("unchecked")
	Graph(int v){
		this.v = v;
		arr = new LinkedList[v];
		
		for(int i=0;i<v;i++) {
			arr[i] = new LinkedList<Integer>();
		}
	}
}

public class AdjacencyListGraph {	
	static void addEdge(Graph g,int src,int dest) {
		//As graph is undirected 
		g.arr[src].add(dest); //Link from source to destination
		g.arr[dest].add(src); //Link from destination to source
	}
	
	static void print(Graph g) {
		for(int i=0;i<g.v;i++) {
			System.out.println("Linked List present at vertex " + i + "is :");
			System.out.print("head");
			for(Integer res : g.arr[i])
				System.out.print("->" + res);
			System.out.println("");
		}
	}
	@SuppressWarnings("unused")
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner Scan = new Scanner(System.in);
		System.out.println("Enter number of vertices ");
		int ver = Scan.nextInt();
		//Graph graph = new Graph(ver);
		Graph graph = new Graph(ver);
		System.out.println("Enter source and destination " );
		int s,d;
		for(int i=0;i<ver;i++) {
			addEdge(graph, Scan.nextInt(), Scan.nextInt());
		}
		print(graph);
	}

}
