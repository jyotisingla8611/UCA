import java.util.*;
public class MyLinkedList implements Iterable<Integer> {

	private Node head;
	private class Node {
		private int data;
		private Node next;
		
		private Node(int data) {
			this.data = data;
			this.next = null;
		}
	}
	
	public void add(int data) {
		if(head == null)
			head = new Node(data);
		else {
			Node t = head;
			while(t.next != null) {
				t = t.next;
			}
			t.next = new Node(data);
		}
	}
	
	@Override
	public Iterator<Integer> iterator() {
		return new CustomIterator();
	}
	
	private  class CustomIterator implements Iterator<Integer>{
		private Node temp = head;
		public boolean hasNext() {
			return  temp != null;
			
		}
		
		public Integer next() {
			int t = temp.data;
			temp = temp.next;
			return t;
			
		}
	}
	
	public static void main(String[] args) {
		MyLinkedList s = new MyLinkedList();
		s.add(1);
		s.add(2);
		s.add(3);
		s.add(4);
		print(s);
	}
	private static void print(Iterable<Integer>i) {
		Iterator<Integer> it = i.iterator();
		while(it.hasNext()) {
			System.out.println(it.next());
		}
	}

}
