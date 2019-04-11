package Graphs;
import java.util.*;
public class Time {
	public static int time  = 0;
	int v;
	LinkedList<Integer>arr[];
	@SuppressWarnings("unchecked")
	Time(int v){
		this.v = v;
		arr =new LinkedList[v];
		
		for(int i = 0;i<v;i++)
			arr[i] = new LinkedList<>();
	}
	
	void insert(int s,int d) {
		arr[s].add(d);
		arr[d].add(s);
	}
	
    void time_calc(int strt,boolean []visit,int[]in,int []out) {
		visit[strt] = true;
		time++;
		in[strt] = time;
		for(int i =0 ;i < arr[strt].size();i++) {
			int x = arr[strt].get(i);
			if(visit[x]==false)
				time_calc(x,visit,in,out);
		}
		time++;
		out[strt] = time;
	}
	public static void main(String...args) {
		//System.out.println("Heya");
		int v = 9;
		Time gr = new Time(v);
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
		int[]timeIn = new int[v];
		int[]timeOut = new int[v];
		boolean[]visit = new boolean[v];
		for(int i=0 ;i<v;i++)
			visit[i] = false;
		gr.time_calc(0,visit,timeIn,timeOut);
		System.out.println("In Time ");
		for(int i : timeIn)
			System.out.print(i + " ");
		System.out.println("\nOut Time ");
		for(int i : timeOut)
			System.out.print(i + " ");
		
	}

}
