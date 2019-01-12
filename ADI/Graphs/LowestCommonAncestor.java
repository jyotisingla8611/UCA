package Graphs;

import java.util.*;

public class LowestCommonAncestor {

	int v;
	LinkedList<Integer> arr[];

	@SuppressWarnings("unchecked")
	LowestCommonAncestor(int v) {
		this.v = v;
		arr = new LinkedList[v];

		for (int i = 0; i < v; i++)
			arr[i] = new LinkedList<>();
	}

	void insert(int s, int d) {
		arr[s].add(d);
		arr[d].add(s);
	}

	private void parent_calc(int it, boolean[] visit, int[] parent) {
		visit[it] = true;

		for (int i = 0; i < arr[it].size(); i++) {
			int u = arr[it].get(i);
			if (visit[u] == false) {
				parent[u] = it;
				parent_calc(u, visit, parent);
			}
		}
	}

	int lca(int x, int y, int[] parent) {
		int res = 0;
		Set<Integer> myset = new HashSet<>();
		while (x != -1) {
			myset.add(x);
			x = parent[x];
		}
		while (y != -1) {
			if (myset.contains(y)) {
				res = y;
				return res;
			}
			myset.add(y);
			y = parent[y];
		}
		return res;
	}

	public static void main(String... args) {
		int v = 9;
		LowestCommonAncestor gr = new LowestCommonAncestor(v);
		gr.insert(0, 1);
		gr.insert(0, 8);
		gr.insert(1, 6);
		gr.insert(1, 8);
		gr.insert(1, 7);
		gr.insert(8, 7);
		gr.insert(3, 8);
		gr.insert(7, 4);
		gr.insert(4, 2);
		gr.insert(4, 5);
		gr.insert(5, 2);

		boolean[] visit = new boolean[v];
		for (int i = 0; i < v; i++)
			visit[i] = false;
		int[] parent = new int[v];
		for (int i = 0; i < v; i++)
			parent[i] = -1;
		gr.parent_calc(0, visit, parent);
		System.out.println("Parent Nodes of a vertex are as : " );
		for(int i : parent)
			System.out.print(i + " ");
		int res = gr.lca(2, 4, parent);
		System.out.println("\nLowest Common Ancestor is as : " + res);
	}

}
