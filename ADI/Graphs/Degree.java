// Directed Graph
package Graphs;

class Gra{
	int v;
	int arr[][];
	
	Gra(int v){
		this.v = v;
		arr = new int[v][];
		for(int i = 0;i<v;i++) {
			arr[i] = new int[v];
		}
	}
}
public class Degree {
	
	public static void add_element(Gra g,int s,int d) {
		g.arr[s][d] = g.arr[s][d] + 1;
	}
	
	public static int indegree(Gra g,int vert) {
		int sum = 0;
		for(int i = 0;i<g.v;i++) {
			sum = sum + g.arr[i][vert];
		}
		return sum;
	}
	
	public static int outdegree(Gra g,int vert) {
		int sum = 0;
		for(int i = 0;i<g.v;i++) {
			sum = sum + g.arr[vert][i];
		}
		return sum;
	}
	
	public static void main(String...args) {
		Gra graph = new Gra(5);
		add_element(graph,0, 1);
		add_element(graph,0, 2);
		add_element(graph,1, 2);
		add_element(graph,2, 0);
		add_element(graph,2, 3);
		add_element(graph,3, 3);
		
		System.out.println("Indegree is as : " + indegree(graph, 3));
		System.out.println("Outdegree is as : " + outdegree(graph, 3));
	}
}
