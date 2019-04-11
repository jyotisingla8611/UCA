/*import java.util.Arrays;

public class MaxIntHeap {
	int capacity = 10;
	int size = 0;
	
	int[] data = new int[capacity];
	
	int getLeftChildIndex(int parentIndex) {
		return 2 * parentIndex + 1;
	}
	int getRightChildIndex(int parentIndex) {
		return 2 * parentIndex + 2;
	}
	int getParentIndex(int childIndex) {
		return (childIndex - 1)/2;
	}
	
	boolean hasLeftChild(int index) {
		return getLeftChildIndex(index) < size;
	}
	boolean hasRightChild(int index) {
		return getRightChildIndex(index) < size;
	}
	boolean hasParent(int index) {
		return getParentIndex(index) < size;
	}
	
	int leftChild(int index) {
		return data[getLeftChildIndex(index)];
	}
	int rightChild(int index) {
		return data[getRightChildIndex(index)];
	}
	int parent(int index) {
		return data[getParentIndex(index)];
	}
	
	void swap(int ind1,int ind2) {
		int temp = data[ind1];
		data[ind1] = data[ind2];
		data[ind2] = temp;
	}
	
	private void ensureExtraCapacity() {
		if (size == capacity) {
			data = Arrays.copyOf(data, capacity * 2);
			capacity *= 2;
		}
	}
	
	public void add(int val) {
		
	}
	
	public int peek() {
		return 0;
	}
	public static void main(String[] args) {
		MaxIntHeap min = new MaxIntHeap();
		min.add(2);
		min.add(4);
		min.add(1);
		min.add(5);
	//	min.add(0);
		System.out.println(min.peek());

	}

}
*/

public class MaxIntHeap{
	int flag ,largest,l,r;
	MaxIntHeap(){
		flag = 0;
	}
	int [] ar = new int[10];
	int size = 0;
	void build_max(int[] ar,int n) {
		for(int i = n/2;i>=1;i--) {
			max_heapify(ar,i,n);
		}
	}
	
	void insert(int val) {
		size++;
		this.ar[size] = val;
		int temp ;
		int i = size;
		while(i>1 && this.ar[i/2] < this.ar[i]) {
			temp = this.ar[i/2];
			this.ar[i/2] = this.ar[i];
			this.ar[i] = temp;
			i = i/2;
		}
	}
	void max_heapify(int[]ar,int i,int n) {
		flag = 0;
		l = 2*i;
		r = (2*i)+1;
		if(l <= n && ar[l] > ar[i]) {
			flag = 1;
			largest = l;
		}
		else if(l <= n && ar[i] > ar[l]) {
			largest = i;
		}
		if(r <= n && ar[r] > ar[largest]) {
			flag = 1;
			largest = r;
		}
		if(flag == 1) {
			int temp;
			temp = ar[i];
			ar[i] = ar[largest];
			ar[largest] = temp;
			max_heapify(ar, largest, n);
		}
	}
	public static void main(String...args) {
		MaxIntHeap max = new MaxIntHeap();
		
		max.insert( 2);
		max.insert( 9);
		max.insert(6);
		max.insert(1);
		max.insert( 5);
		max.insert( 4);
		max.insert( 3);
		System.out.println(max.ar[0]);
	}
}