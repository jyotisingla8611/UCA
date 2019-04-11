/*Given the total number of courses and a list of
prerequisite pairs, is it possible for you to finish all courses. return 1/0 
		if it is possible/not possible.
The list of prerequisite pair are given in two integer arrays B
and C where B[i] is a prerequisite for C[i].

 Example: If N = 3 and the prerequisite pairs are [1,2] and [2,3], 
 then you can finish courses in the following order: 1, 2 and 3.
 But if N = 2 and the prerequisite pairs 
 are [1,2] and [2,1], then it is not possible for you to finish all the courses.
*/

package InterviewBit;
import java.util.*;
public class Prerequisites {
	
	class Graph{
	    int v;
	    LinkedList<Integer>arr[];
	    
	    @SuppressWarnings("unchecked")
		Graph(int v){
	        this.v =  v;
	        arr = new LinkedList[v];
	        
	        for(int i = 0 ; i < v ; i++)
	           arr[i] = new LinkedList<Integer>();
	    }
	    
	     void addEdge(int s,int d){
	        arr[s].add(d);    
	    }
	}


	static boolean  directedCycle(Graph g ,int s ,boolean[] visit,boolean[] expl){
	    Stack<Integer> stack = new Stack<>(); 
	          
	        stack.push(s); 
	          
	        while(stack.empty() == false) 
	        { 
	            s = stack.peek(); 
	            stack.pop(); 
	           
	            if(visit[s] == false) 
	            { 
	                visit[s] =  true; 
	                expl[s] = true;
	            } 
	      
	            Iterator<Integer> itr = g.arr[s].iterator(); 
	            while (itr.hasNext())  
	            { 
	                int it = itr.next(); 
	                if(visit[it] == false) 
	                    stack.push(it); 
	                else{
	                    boolean x = expl[it];
	                    if(x == true)
	                      return true;
	                }
	            } 
	              
	        }
	        return false;
	}

	  public  int solve(int A, ArrayList<Integer> B, ArrayList<Integer> C) {
	        Graph g = new Graph(A);
	    for(int i = 0 ;i < B.size() ; i++){
	        int x = B.get(i);
	        int y = C.get(i);
	        x = x-1;
	        y = y-1;
	        B.set(i,x);
	        C.set(i,y);
	    }
	    boolean[] visit = new boolean[A];
	    boolean[] expl = new boolean[A];
	    for(int i = 0; i < B.size() ; i++)
	        g.addEdge(B.get(i),C.get(i));
	    for(int i = 1 ;i < A;i++){
	        Arrays.fill(visit,false);
	        Arrays.fill(expl,false);
	        if(directedCycle(g,i,visit,expl) == true){
	           return 0;
	        }
	    }      
	      return 1;
	    }
	    
	    public static void main(String...args){
	        Prerequisites pr = new Prerequisites();
	        int n = 3;
	        ArrayList<Integer>a1 = new ArrayList<Integer>();
	        a1.add(1);
	        a1.add(2);
	        ArrayList<Integer>a2 = new ArrayList<Integer>();
	        a2.add(2);
	        a2.add(3);
	        
	        int res = pr.solve(n,a1,a2);
	        System.out.println("Status is as : " + res);
	    }
}
