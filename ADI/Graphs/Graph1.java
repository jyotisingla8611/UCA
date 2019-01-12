package Graphs;

import java.util.*;
public class Graph1 {
	public static int time=0;
	static void insert(Integer x,Integer y,LinkedList<Integer>[] arr) {
		arr[x].add(y);
		arr[y].add(x);
	}
	static void printList(LinkedList<Integer> arr) {
		System.out.println(arr);
	}
	static void dfs(int u,int visited[],LinkedList<Integer>[] arr,int depth[],int size[],int count[],int[] tin,int[] tout,int[] parent) {
		visited[u] = 1;
		time++;
		tin[u]=time;
		for(int i=0;i<arr[u].size();i++) {
			int v = arr[u].get(i);
			if(visited[v]!=0)
				continue;
			parent[v]=u;
			depth[v] = depth[u]+1;
			dfs(v,visited,arr,depth,size,count,tin,tout,parent);
			size[u]=size[u]+size[v];
			if(size[v]==1)
				(count[u])++;
			if(count[v]>0)
				count[u]+=count[v];
		}
		visited[u]=2;
		time++;
		tout[u]=time;
		
		System.out.print(u+" ");
	}
	@SuppressWarnings({ "unchecked" })
	public static void main(String[] args) {
		//Scanner s = new Scanner(System.in);
		//int n = s.nextInt();
		int n = 9;
		LinkedList<Integer>[] arr = new LinkedList[n];
		for(int i=0;i<n;i++)
			arr[i] = new LinkedList<Integer>();
		insert(0,1,arr);
		insert(0,8,arr);
		insert(1,6,arr);
		insert(1,8,arr);
		insert(1,7,arr);
		insert(8,7,arr);
		insert(3,8,arr);
		insert(7,4,arr);
		insert(4,2,arr);
		insert(4,5,arr);
		insert(5,2,arr);
		System.out.print("Adjacency List of 0 is : \n");
		printList(arr[0]);
		int visited[] = new int[n];
		for(int i=0;i<n;i++)
			visited[i]=0;
		int depth[] = new int[n];
		for(int i=0;i<n;i++)
			depth[i]=1;
		int size[] = new int[n];
		for(int i=0;i<n;i++)
			size[i]=1;
		int count[] = new int[n];
		for(int i=0;i<n;i++)
			count[i]=0;
		int tin[] = new int[n];
		for(int i=0;i<n;i++)
			tin[i]=0;
		int tout[] = new int[n];
		for(int i=0;i<n;i++)
			tout[i]=0;
		int parent[] = new int[n];
		for(int i=0;i<n;i++)
			parent[i]=-1;
		System.out.print("The dfs of this graph is : \n");
		dfs(0,visited,arr,depth,size,count,tin,tout,parent);
		System.out.print("\nThe depth of all vertices is :\n ");
		for(int i:depth)
			System.out.print(i+" ");
		System.out.print("\nThe size of subtree for each vertex is :\n ");
		for(int i:size)
			System.out.print(i+" ");
		System.out.print("\nThe number of leaf nodes for each vertex's subtree are :\n ");
		for(int i:count)
			System.out.print(i+" ");
		System.out.print("\nThe degree of each vertex is : \n");
		for(int i=0;i<n;i++)
			System.out.print(arr[i].size()+" ");
		System.out.print("\nThe time in for each vertex is : \n");
		for(int i:tin)
			System.out.print(i+" ");
		System.out.print("\nThe time out for each vertex is : \n");
		for(int i:tout)
			System.out.print(i+" ");
		System.out.print("\nThe parent for each vertex is : \n");
		for(int i:parent)
			System.out.print(i+" ");
	}
}