/*Topological Sorting for a graph is not possible if the graph is not a Directed
 *Acyclic Gra11ph.
 * 
 *Starting vertex of this will be the vertex with indegree as 0
 *
 */

package Graphs;
import java.util.*;

class Gra11{
	int v;
	ArrayList<ArrayList<Integer>>arr;
	
	Gra11(int v){
		this.v = v;
		arr = new ArrayList<ArrayList<Integer>>();
		
		for(int i = 0 ;i<v;i++)
		  arr.add(i,new ArrayList<Integer>());
	}
	
	void addEdge(int u,int v) {
		arr.get(u).add(v);
	}

	@SuppressWarnings("rawtypes")
	public void topologicalSort() {
		Stack stack = new Stack(); 
		  
        boolean visited[] = new boolean[v]; 
        for (int i = 0; i < v; i++) 
            visited[i] = false; 
  
        for (int i = 0; i < v; i++) 
            if (visited[i] == false) 
                topologicalSortUtil(i, visited, stack); 
  
        while (stack.empty()==false) 
            System.out.print(stack.pop() + " "); 
		
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	private void topologicalSortUtil(int u, boolean[] visited, Stack stack) {
		visited[u] = true;
		int i;
		Iterator<Integer>it = arr.get(u).iterator();
		while(it.hasNext()) {
			i = it.next();
			if(!visited[i])
				topologicalSortUtil(i,visited,stack);
		}
		stack.add(u);
	}
}
public class TopologicalSort {
	
	public static void main(String args[]) 
    { 
        // Create a graph given in the above diagram 
        Gra11 g = new Gra11(6); 
        g.addEdge(5, 2); 
        g.addEdge(5, 0); 
        g.addEdge(4, 0); 
        g.addEdge(4, 1); 
        g.addEdge(2, 3); 
        g.addEdge(3, 1); 
  
        System.out.println("Following is a Topological " + 
                           "sort of the given graph"); 
        g.topologicalSort(); 
    } 

}
