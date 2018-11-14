import java.util.Arrays;

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
	
	/
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
