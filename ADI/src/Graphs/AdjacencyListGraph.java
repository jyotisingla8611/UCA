package Graphs;
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
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner Scan = new Scanner(System.in);
		System.out.println("Enter number of vertices ");
		int ver = Scan.nextInt();
		Graph graph = new Graph(ver);
		System.out.println("Enter source and destination " );
		for(int i=0;i<ver;i++) {
			addEdge(graph, Scan.nextInt(), Scan.nextInt());
		}
		print(graph);
	}

}




/*
package Graphs;
import java.util.*;

class Graph{
	int v;
	ArrayList<ArrayList<Integer>>arr;

	Graph(int v){
		this.v = v;
		arr = new ArrayList<ArrayList<Integer>>();
		
		for(int i=0;i<v;i++) {
			arr.add(new ArrayList<Integer>());
		}
	}
}

public class AdjacencyListGraph {	
	static void addEdge(Graph g,int src,int dest) {
		//As graph is undirected 
		g.arr.get(src).add(dest); //Link from source to destination
		g.arr.get(dest).add(src); //Link from destination to source
	}
	
	static void print(Graph g) {
		for(int i=0;i<g.v;i++) {
			System.out.println("Linked List present at vertex " + i + "is :");
			System.out.print("head");
			for(Integer res : g.arr.get(i))
				System.out.print("->" + res);
			System.out.println("");
		}
		
	}
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner Scan = new Scanner(System.in);
		System.out.println("Enter number of vertices ");
		int ver = 5;
		Graph graph = new Graph(ver);
		System.out.println("Enter source and destination " );
		addEdge(graph,0,3);
		addEdge(graph,1,3);
		addEdge(graph,4,3);
		addEdge(graph,2,4);
		addEdge(graph,4,1);
		print(graph);
	}

}
*/