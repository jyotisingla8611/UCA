package Graphs;

import java.util.*;

public class DetectCycleUndirected {
	
	int v;
	LinkedList<Integer> arr[];
	
	@SuppressWarnings("unchecked")
	public DetectCycleUndirected(int v) {
		this.v = v;
		arr = new LinkedList[v];
		
		for(int i = 0;i<v;i++)
			arr[i] = new LinkedList<Integer>();
	}
	
	public void addEdge(int s,int d) {
		arr[s].add(d);
		arr[d].add(s);
	}
	
	public boolean hasCycle(int s,boolean[]visit,int parent) {
		
		visit[s] = true;
		
		Iterator<Integer>it = arr[s].iterator();
		
		while(it.hasNext()) {
			int x = it.next();
			if(visit[x] == false) {
				if(hasCycle(x, visit, s))
					return true;
			}
			else if(x!=parent)
				return true;
		}
		return false;
	}
	public boolean isCyclic() {
		boolean[]visit = new boolean[v];
		
		for(int i = 0; i<v ;i++)
			visit[i] = false;
		
		for(int i=0;i<v;i++) {
			if(!visit[i])
			if(hasCycle(i,visit,-1))
				return true;
		}
		return false;
	}
	
	public static void main(String...args) {
		DetectCycleUndirected g1 = new DetectCycleUndirected(5);
		g1.addEdge(1, 0); 
        g1.addEdge(0, 2); 
        g1.addEdge(2, 0); 
        g1.addEdge(0, 3); 
        g1.addEdge(3, 4); 
        if (g1.isCyclic()) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't contains cycle"); 
  
        DetectCycleUndirected g2 = new DetectCycleUndirected(3); 
        g2.addEdge(0, 1); 
        g2.addEdge(1, 2); 
        if (g2.isCyclic()) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't contains cycle"); 
        DetectCycleUndirected g3 = new DetectCycleUndirected(6); 
        g3.addEdge(0, 1); 
        g3.addEdge(1, 2); 
        g3.addEdge(3, 4); 
        g3.addEdge(2, 4); 
        g3.addEdge(2, 5); 
        g3.addEdge(4, 5); 
        if (g3.isCyclic()) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't contains cycle"); 
	}
}
