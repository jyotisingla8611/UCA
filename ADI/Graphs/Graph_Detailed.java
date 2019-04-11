package Graphs;
import java.util.*;
public class Graph_Detailed {
	int v;
	LinkedList<Integer>arr[];
	
	@SuppressWarnings("unchecked")
	Graph_Detailed(int v){
		this.v = v;
		arr = new LinkedList[v];
		for(int i = 0;i<v;i++)
			arr[i] = new LinkedList<Integer>();
	}
	
	void add_Element(int s,int d) {
		arr[s].add(d);
	}
	
	void addVertex() {
		v = v+1;
	}
	
	void removeEdge(int s,int d) {
		int ind = arr[s].indexOf(d);
		arr[s].remove(ind);
	}
	
	public List<Integer> getNeighbors(int v){
		 
		    List<Integer> neighbors = new ArrayList<Integer>();
		    for (Integer x : arr[v]) {
		      neighbors.add(x);
		    }
		    
		    return neighbors;
	}
	
	public List<Integer> getNeighborsTwoApart(int v)  {
		
		    List<Integer> oneApart = getNeighbors(v);
		    ArrayList<Integer> twoApart = new ArrayList<Integer>();
		    for(Integer i : oneApart) {
		    	for(Integer j : arr[i])
		    		twoApart.add(j);
		    }
		    return twoApart;
		}
	
	 void print( ) {
		for(int i=0;i<v;i++) {
			System.out.println("Linked List present at vertex " + i + "is :");
			System.out.print("head");
			for(Integer res : arr[i])
				System.out.print("->" + res);
			System.out.println("");
		}
	}
	public static void main(String...args) {
		Graph_Detailed graph = new Graph_Detailed(5);
		graph.add_Element(0,1);
		graph.add_Element(0,2);
		graph.add_Element(1,2);
		graph.add_Element(2,3);
		graph.add_Element(3,3);
		graph.add_Element(0,4);
		graph.add_Element(2,4);
		graph.add_Element(3,1);
		graph.add_Element(4,1);
		graph.add_Element(4,3);
		System.out.println("The adjacency Lists are as : " );
		graph.print();
		graph.removeEdge(0, 2);
		System.out.println("\nThe Adjacency lists after removing an edge are as : ");
		graph.print();
		System.out.println("\nThe Neighbours of a vertex are as : " );
		List<Integer>res = graph.getNeighbors(2);
		for(Integer i : res)
			System.out.print(i + " ");
		System.out.println("\nThe Two Distanced  Neighbours of a vertex are as : " );
		List<Integer>res1 = graph.getNeighborsTwoApart(2);
		for(Integer i : res1)
			System.out.print(i + " ");
	}
}
