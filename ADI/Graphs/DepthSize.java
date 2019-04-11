package Graphs;
import java.util.*;
public class DepthSize {
	
	int v;
	LinkedList<Integer>arr[];
	@SuppressWarnings("unchecked")
	DepthSize(int v){
		this.v = v;
		arr =new LinkedList[v];
		
		for(int i = 0;i<v;i++)
			arr[i] = new LinkedList<>();
	}
	
	void insert(int s,int d) {
		arr[s].add(d);
		arr[d].add(s);
	}
	
	void find(int u,boolean[]visit,int[]d,int []s) {
		visit[u] = true;
		for(int i=0;i<arr[u].size();i++) {
			int v = arr[u].get(i);
			if(visit[v] == false) {
			d[v] = d[u]+1;
			find(v,visit,d,s);
			s[u]=s[u]+s[v];
			}
		}
	}
	
	public static void main(String...args) {
		int v = 9;
		DepthSize gr = new DepthSize(v);
		gr.insert(0,1);
		gr.	insert(0,8);
		gr.insert(1,6);
		gr.insert(1,8);
		gr.insert(1,7);
		gr.insert(8,7);
		gr.insert(3,8);
		gr.insert(7,4);
		gr.insert(4,2);
		gr.insert(4,5);
		gr.insert(5,2);
		boolean[]visit = new boolean[v];
		for(int i=0 ;i<v;i++)
			visit[i] = false;
		int[]depth = new int[v];
		for(int i=0;i<v;i++)
			depth[i] = 1;
		int[]size = new int[v];
		for(int i = 0;i<v;i++)
			size[i] = 1;
		gr.find(0,visit,depth,size);
		System.out.println("Depth is as : " );
		for(int i : depth)
			System.out.print(i + " ");
		System.out.println("\nSize is as : " );
		for(int i : size)
			System.out.print(i +" ");
		
	}

}
