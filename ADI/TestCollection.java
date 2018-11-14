import java.util.ArrayList;
import java.util.Collection;

public class TestCollection {

	public static void main(String[] args) {
		
		Collection<String> collection = new ArrayList<String>();
		
		collection.add("Zero");
		collection.add("one");
		collection.add("two");
		
		// for-each loop
		for(String s : collection) {
			System.out.println("value = " + s);
		}
	}

}
