package Graphs;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Vector;

class Graphh{
	int v;
	LinkedList<Integer>list[];
	@SuppressWarnings("unchecked")
	Graphh(int r){
		v = r;
		list = new LinkedList[v];
		for(int i=0;i<r;i++)
			list[i] = new LinkedList<Integer>();
	}
}

public class DepthFrstDSearch{
	public static void add(Graphh g , int s,int d) {
		g.list[s].add(d);
	}
	
	public static void DFS(Graphh g,int init) {
		boolean visit[] = new boolean[g.v];
		for(int i = 0;i<g.v;i++)
			visit[i] = false;
		
		dfs(g,init,visit);
	}
	
	private static void dfs(Graphh g,int init, boolean[] visit) {
		visit[init] = true;
		System.out.print(init + " ");
		
		Iterator<Integer> i = g.list[init].iterator(); 
		while(i.hasNext()) {
			int n = i.next();
			if(visit[n] == false)
				dfs(g,n,visit);
		}
	}

	
	public static void DFS_iter(Graphh g , int s) 
    { 
        // Initially mark all vertices as not visited 
        Vector<Boolean> visited = new Vector<Boolean>(g.v); 
        for (int i = 0; i < g.v; i++) 
            visited.add(false); 
  
        // Create a stack for DFS 
        Stack<Integer> stack = new Stack<>(); 
          
        // Push the current source node 
        stack.push(s); 
          
        while(stack.empty() == false) 
        { 
            // Pop a vertex from stack and print it 
            s = stack.peek(); 
            stack.pop(); 
              
            // Stack may contain same vertex twice. So 
            // we need to print the popped item only 
            // if it is not visited. 
            if(visited.get(s) == false) 
           { 
                System.out.print(s + " "); 
                visited.set(s, true); 
            } 
              
            // Get all adjacent vertices of the popped vertex s 
            // If a adjacent has not been visited, then puah it 
            // to the stack. 
            Iterator<Integer> itr = g.list[s].iterator(); 
              
            while (itr.hasNext())  
            { 
                int v = itr.next(); 
                if(!visited.get(v)) 
                    stack.push(v); 
            } 
              
        } 
    } 
	public static void main(String...args) {
		Graphh g = new Graphh(4);
		add(g,0, 1);
		add(g,0, 2);
		add(g,1, 2);
		add(g,2, 0);
		add(g,2, 3);
		add(g,3, 3);
		System.out.println("The DFS of given Graphh is as : " );
		DFS(g,2);
		System.out.println("\nThe DFS using Iterative : " );
	    DFS_iter(g,2);	
	}
}