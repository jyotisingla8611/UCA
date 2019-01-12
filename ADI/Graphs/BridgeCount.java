//Number of Bridge Edges in a Graph in Undirected graph

// To find in directed just calc degree = indegree + outdegree

package Graphs;
import java.util.*;
public class BridgeCount {
	
	int v;
	static LinkedList<Integer>arr[];
	@SuppressWarnings("unchecked")
	BridgeCount(int v){
		this.v = v;
		arr = new LinkedList[v];
		
		for(int i = 0; i < v ; i++)
			arr[i] = new LinkedList<>();
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
	
	void add(int s,int d) {
		arr[s].add(d);
		arr[d].add(s);
	}
	
	public int outdegree(int ver) {
		int degree;
		degree = arr[ver].size();
		return degree;
	}
	
	void clear(int x){
	    for(int i = 0;i<v;i++){
	        if(arr[i].contains(x)){
	            int ind = arr[i].indexOf(x);
	            arr[i].remove(ind);
	        }
	    }
	    arr[x].clear();
	}
	public int graph1(){
	    int count = 0;
	    for(int i = 0;i<v;i++){
	        int deg = outdegree(i);
	        if(deg == 1){
	            count++;
	            System.out.println("Bridge is of " + i + "\n" );
	            clear(i);
	        }
	    }
	    return count;
	}
	public static void main(String...args) {
		BridgeCount g = new BridgeCount(5);
		g.add(0, 1);
		g.add(0, 2);
		g.add(0, 3);
		g.add(1, 2);
		g.add(3, 4);
		int count = 0;
		g.print();
		for(int i=0;i<5;i++){
		   count +=  g.graph1();
		}
		System.out.println("Bridge edges are : " + count);
	}
}
