// Leaf Nodes : If they are assumed to be the ones wd degree 1
package Graphs;
import java.util.*;
public class LeafNodes {
	
		int v;
		LinkedList<Integer>arr[];
		
		@SuppressWarnings("unchecked")
		LeafNodes(int v){
			this.v = v;
			arr = new LinkedList[v];
			for(int i= 0 ;i <v;i++) {
				arr[i] = new LinkedList<>();
			}
		}
	
	void add (int s,int d) {
		arr[s].add(d);
	}
	
	public int indegree(int ver) {
		int degree = 0;
		for(int i = 0;i<v;i++) {
			if(arr[i].contains(ver))
				degree++;
		}
		return degree;
	}
	
	public int outdegree(int ver) {
		int degree;
		degree = arr[ver].size();
		return degree;
	}
	
	int leafNodes() {
		int count = 0;
		int temp = 0;
		for(int i = 0;i<v;i++) {
			count = indegree(i) + outdegree(i);
			if(count == 1)
			  temp++;
		}
	    return temp;
	}
	
	public static void main(String...args) {
		LeafNodes g = new LeafNodes(7);
		g.add(1, 2);
		g.add(1, 3);
		g.add(2, 3);
		g.add(2, 6);
		g.add(3, 4);
		g.add(3, 5);
		g.add(3, 7);
		g.add(4, 7);
		System.out.println("Number of leaf nodes are as : " + g.leafNodes());
	}
}
