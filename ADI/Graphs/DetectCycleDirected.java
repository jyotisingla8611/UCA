package Graphs;

import java.util.*;
class Graphu{
	int v;
	LinkedList<Integer>arr[];

	@SuppressWarnings("unchecked")
	Graphu(int v){
		this.v = v;
		arr = new LinkedList[v];
		
		for(int i=0;i<v;i++) {
			arr[i] = new LinkedList<Integer>();
		}
	}
}
public class DetectCycleDirected {
	
	public static boolean has(int s ,int v,LinkedList<Integer>[] alist,boolean[] visited,boolean[] explored){
        Stack<Integer> stack = new Stack<>(); 
          
        stack.push(s); 
          
        while(stack.empty() == false) 
        { 
          
            s = stack.peek(); 
            stack.pop(); 
           
            if(visited[s] == false) 
            { 
                visited[s] =  true; 
                explored[s] = true;
            } 
      
            Iterator<Integer> itr = alist[s].iterator(); 
            while (itr.hasNext())  
            { 
                int it = itr.next(); 
                if(visited[it] == false) 
                    stack.push(it); 
                else{
                    boolean x = explored[it];
                    if(x == true)
                      return true;
                }
            } 
              
        }
        return false;
    }
    public static boolean hasCycle(int v,LinkedList<Integer>[] alist) 
     {
         boolean[]visit = new boolean[10000];
         boolean[]explore = new boolean[10000];
         Arrays.fill(visit,false);
         Arrays.fill(explore,false);
         boolean result = false;
         for(int i = 0 ;i <v;i++){
             result = has(i ,v,alist,visit,explore);
             Arrays.fill(visit,false);
             Arrays.fill(explore,false);
             if(result == true){
                return true;
             }
         }
         return result;
     }
	
	static void add(Graphu g,int src,int dest) {
		//As graph is undirected 
		g.arr[src].add(dest); //Link from source to destination
		g.arr[dest].add(src); //Link from destination to source
	}
	
	public static void main(String[] args) {
		int ver = 4;
		Graphu graph = new Graphu(ver);
			add(graph,0, 1);
			add(graph,0, 2);
			add(graph,1, 2);
			add(graph,2, 0);
			add(graph,2, 3);
			add(graph,3, 3);
			boolean res = hasCycle(graph.v,graph.arr);
			if(res == true)
				System.out.println("Cycle is present here ");
			else
				System.out.println("Cycle is not present here");
	}


}
