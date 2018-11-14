import java.util.ArrayList;
import java.util.*;


public class TestIterable {

	/*public static void main(String[] args) {
		List<Integer> s = new ArrayList<>();
		
		s.add(1);
		s.add(2);
		s.add(3);
		
		Iterator<Integer> it = s.iterator();
		
		while(it.hasNext()) {
			System.out.println(it.next());
		}
	}*/
	
	public static void main(String[] args) {
		Set<Integer>s = new HashSet<>();
		s.add(1);
		s.add(2);
		print(s);
	}
	private static void print(Iterable<Integer>i) {
		Iterator<Integer> it = i.iterator();
		while(it.hasNext()) {
			System.out.println(it.next());
		}
	}

}
