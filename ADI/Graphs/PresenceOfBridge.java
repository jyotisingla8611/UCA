/*TO check bridge is there or not
     calculate degreee of each node
     if degree = 1;i.e bridge vertex del the edge 
     Again repeat{
    	 cal degree;
    	 if deg == 1
    			 del edge;
     }
*/
package Graphs;

import java.util.*;
public class PresenceOfBridge {
	int v;
	int time = 0;
	LinkedList<Integer>arr[];
	@SuppressWarnings("unchecked")
	public PresenceOfBridge(int v) {
		this.v = v;
		arr = new LinkedList[v];
		for(int i = 0;i<v;i++)
			arr[i] = new LinkedList<>();
	}
	
	 void insert(int x,int y) {
		arr[x].add(y);
		arr[y].add(x);
	}
	 
	int bridgeUtil(int st,boolean[]v,int []l,int[]d,int[]p,int count) {
		v[st] = true;
		d[st] = l[st] = ++time;
		for(int i = 0;i<arr[st].size();i++) 
        { 
            int st1 = arr[st].get(i);  // v is current adjacent of u 
  
            // If v is not visited yet, then make it a child 
            // of u in DFS tree and recur for it. 
            // If v is not visited yet, then recur for it 
            if (v[st1] == false) 
            { 
                p[st1] = st; 
                count = bridgeUtil(st1, v, l,d,p,count); 
  
                // Check if the subtree rooted with v has a 
                // connection to one of the ancestors of u 
                l[st]  = Math.min(l[st], l[st1]); 
  
                // If the lowest vertex reachable from subtree 
                // under v is below u in DFS tree, then u-v is 
                // a bridge 
                if (l[st1] > d[st]) {
                    System.out.println(st+" "+st1);
                    count++;
                }
            } 
  
            // Update low value of u for parent function calls. 
            else if (st1 != p[st]) 
                l[st]  = Math.min(l[st], d[st1]); 
        } 
		return count;
	}
	void bridge(){
		int[] low = new int[v];
		int[] disc = new int[v];
		int[] parent = new int[v];
		boolean[] visit = new boolean[v];
		for(int i=0;i<v;i++) {
			visit[i] = false;
			parent[i] = -1;
		}
		int count = 0;
		int res = 0;
		for(int i = 0;i<v;i++)
		{
			count = 0;
			if(visit[i] == false)
				res += bridgeUtil(i,visit,low,disc,parent,count);
		}
		System.out.println("Number of bridges are as : " + res);
	}
	
	public static void main(String[] args) {
		int n = 9;
		PresenceOfBridge gr = new PresenceOfBridge(n);
		@SuppressWarnings("unchecked")
		LinkedList<Integer>[] arr = new LinkedList[n];
		for(int i=0;i<n;i++)
			arr[i] = new LinkedList<Integer>();
		gr.insert(0,1);
		gr.insert(0,8);
		gr.insert(1,6);
		gr.insert(1,8);
		gr.insert(1,7);
		gr.insert(8,7);
		gr.insert(3,8);
		gr.insert(7,4);
		gr.insert(4,2);
		gr.insert(4,5);
		gr.insert(5,2);	
		gr.bridge();
	}
}

