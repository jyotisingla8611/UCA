package Trees;

import java.util.Random;

@SuppressWarnings("unused")
public class TestBST {

	private static BST<Integer, String> bst;

	public static void main(String[] args) {
		BST<Integer,String> bst = new BST<>();
		
		/*Random r = new Random();
		for(int i=0;i<100;i++) {
			//bst.add(r.nextInt(100), "Some Value");
			testRun();
		}*/
		bst.add(5, "five");
		bst.add(6, "six");
		bst.add(1, "one");
		bst.add(2, "two");
		bst.add(7, "seven");
		
		System.out.println(bst.get(1));
		System.out.println(bst.get(8));
		
		System.out.println(bst.height());
	}

	/*private static void testRun() {
		// TODO Auto-generated method stub
		System.out.println(bst.height());

	}
*/
}
