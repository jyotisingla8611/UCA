package Graphs;
import java.util.*;
public class LeafNodeSubtree {
	
	int v;
	LinkedList<Integer>arr[];
	@SuppressWarnings("unchecked")
	LeafNodeSubtree(int v){
		this.v = v;
		arr =new LinkedList[v];
		
		for(int i = 0;i<v;i++)
			arr[i] = new LinkedList<>();
	}
	
	private void leaf_calc(int u, boolean[] visit, int[] leaf,int[]size) {
		visit[u] = true;
		for(int i=0;i<arr[u].size();i++) {
			int v = arr[u].get(i);
			if(visit[v] == false) {
			leaf_calc(v,visit,leaf,size);
			size[u]=size[u]+size[v];
			if(size[v] == 1)
				(leaf[u])++;
			if(leaf[v]>0)
				leaf[u]+=leaf[v];
			}
		}
	}

	void insert(int s,int d) {
		arr[s].add(d);
		arr[d].add(s);
	}
	
	public static void main(String...args) {
		int v = 9;
		LeafNodeSubtree gr = new LeafNodeSubtree(v);
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
		int[]leaf = new int[v];
		for(int i= 0;i<v;i++)
			leaf[i] = 0;
		int size[] = new int[v];
		for(int i=0;i<v;i++)
			size[i]=1;
		gr.leaf_calc(0,visit,leaf,size);
		System.out.println("The number of leaf nodes for each vertex's subtree are :" );
		for(int i : leaf)
			System.out.print(i + " ");
	}
}
