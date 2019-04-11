package Graphs;

public class Islands {
	int v;
	int[][]arr;
	
	Islands(int v) {
		this.v = v;
		arr = new int[v][];
		for(int i = 0;i <v;i++) {
			arr[i] = new int[v];
		}
	}

	void add(int i,int j) {
		arr[i][j] = 1;
	}
	
	void island_util(int i,int j) {
		if(i<0 || i>= arr.length)
			return ;
		if(j<0 || j>=arr.length)
			return;
		if(arr[i][j] != 1)
			return ;
		arr[i][j] = -1;

		island_util(i,j+1);
		island_util(i, j-1);
		island_util(i+1, j);
		island_util(i-1, j);
		island_util(i+1, j+1);
		island_util(i-1, j-1);
		island_util(i+1, j-1);
		island_util(i-1, j+1);
	}
	
	int numberOf() {
		int count = 0;
		for(int i = 0;i<arr.length;i++) {
			for(int j = 0;j<arr[i].length;j++) {
				if(arr[i][j] == 1)
				{
					//System.out.println("i + " + i);
					count++;
					island_util(i,j);
				}
			}
		}
		return count;
	}
	
	public static void main(String...args) {
		Islands gr = new Islands(5);
		gr.add(0, 0);
		gr.add(0, 1);
		gr.add(1, 3);
		gr.add(1, 4);
		gr.add(2, 2);
		gr.add(3, 0);
		gr.add(3, 3);
		gr.add(4, 2);
		gr.add(4, 4);
		int res = gr.numberOf();
		System.out.println("Number of Islands are as : " + res);
	}
}
