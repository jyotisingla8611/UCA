package Graphs;
import java.util.*;
public class Degree_List {
	
	int v;
	static LinkedList<Integer>arr[];
	
	@SuppressWarnings("unchecked")
	Degree_List(int v){
		this.v = v;
		arr = new LinkedList[v];
		
		for(int i = 0; i < v ; i++)
			arr[i] = new LinkedList<>();
		
	}
	
	void add(int s,int d) {
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
	public static void main(String...args) {
		Degree_List g = new Degree_List(4);
		g.add(0, 1);
		g.add(0, 2);
		g.add(1, 2);
		g.add(2, 0);
		g.add(2, 3);
		g.add(3, 3);
		
		System.out.println("Indegree is as : " + g.indegree( 3));
		System.out.println("Outdegree is as : " + g.outdegree(3));

	}
}
