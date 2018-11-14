class n {

	int data;
	int height;
	n left;
	n right;

	n(int d) {
		data = d;
		height = 1;
	}

}

public class AVLTree {

	n root;

	int height(n n) {
		if (n == null)
			return 0;

		return n.height;
	}

	int max(int a, int b) {
		return (a > b) ? a : b;
	}

	n leftRotate(n x) {
		n y = x.right;
		n z = y.left;
		y.left = x;
		x.right = z;

		x.height = max(height(x.left), height(x.right)) + 1;
		y.height = max(height(y.left), height(y.right)) + 1;

		return y;
	}

	n rightRotate(n x) {
		n y = x.left;
		n z = y.right;
		y.right = x;
		x.left = z;

		x.height = max(height(x.left), height(x.right)) + 1;
		y.height = max(height(y.left), height(y.right)) + 1;

		return y;
	}

	int getbal(n n) {
		if (n == null)
			return 0;
		return (height(n.left) - height(n.right));
	}

	void preorder(n n) {
		if (n != null) {
			System.out.print(n.data + " ");
			preorder(n.left);
			preorder(n.right);
		}
	}

	n insert(n n, int d) {

		if (n == null)
			return (new n(d));

		if (d < n.data)
			n.left = insert(n.left, d);
		else if (d > n.data)
			n.right = insert(n.right, d);
		/*
		 * else return n;
		 */
		n.height = 1 + max(height(n.left), height(n.right));

		int bal = getbal(n);

		/*
		 * if(bal > 1) { if(getbal(n.left) >= 0) return rightRotate(n); else { n.left =
		 * leftRotate(n.left); return rightRotate(n); } }
		 * 
		 * if(bal < 1) { if(getbal(n.right) <= 0) return leftRotate(n); else { n.right =
		 * rightRotate(n.right); return leftRotate(n); } }
		 */

		if (bal > 1 && d < n.left.data)
			return rightRotate(n);

		// Right Right Case
		if (bal < -1 && d > n.right.data)
			return leftRotate(n);

		// Left Right Case
		if (bal > 1 && d > n.left.data) {
			n.left = leftRotate(n.left);
			return rightRotate(n);
		}

		// Right Left Case
		if (bal < -1 && d < n.right.data) {
			n.right = rightRotate(n.right);
			return leftRotate(n);
		}

		return n;

	}

	public static void main(String[] args) {

		AVLTree tree = new AVLTree();

		tree.root = tree.insert(tree.root, 10);
		tree.root = tree.insert(tree.root, 20);
		tree.root = tree.insert(tree.root, 30);
		tree.root = tree.insert(tree.root, 40);
		tree.root = tree.insert(tree.root, 50);
		tree.root = tree.insert(tree.root, 25);
		tree.preorder(tree.root);

	}

}
