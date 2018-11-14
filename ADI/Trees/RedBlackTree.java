package Trees;
// Left Leaning Red Black Tree

class node {
	node left, right;
	int data;

	// red ==> true, black ==> false
	boolean color;

	node(int data) {
		this.data = data;
		left = null;
		right = null;

		color = true;
	}
}

public class RedBlackTree {

	private static node root = null;

	node rotateLeft(node myNode) {
		System.out.printf("Left rotation !\n");
		node child = myNode.right;
		node childLeft = child.left;

		child.left = myNode;
		myNode.right = childLeft;

		return child;
	}

	node rotateRight(node myNode) {
		System.out.printf("Right rotation !l\n");
		node child = myNode.left;
		node childRight = child.right;

		child.right = myNode;
		myNode.left = childRight;

		return child;
	}

	boolean isRed(node myNode) {
		if (myNode == null)
			return false;
		return (myNode.color == true);
	}

	void swapColors(node node1, node node2) {
		boolean temp = node1.color;
		node1.color = node2.color;
		node2.color = temp;
	}

	node insert(node myNode, int data) {
		if (myNode == null)
			return new node(data);

		if (data < myNode.data)
			myNode.left = insert(myNode.left, data);

		else if (data > myNode.data)

			myNode.right = insert(myNode.right, data);

		else
			return myNode;

		if (isRed(myNode.right) && !isRed(myNode.left)) {
			myNode = rotateLeft(myNode);

			swapColors(myNode, myNode.left);

		}

		if (isRed(myNode.left) && isRed(myNode.left.left)) {
			myNode = rotateRight(myNode);
			swapColors(myNode, myNode.right);
		}

		if (isRed(myNode.left) && isRed(myNode.right)) {
			myNode.color = !myNode.color;

			myNode.left.color = false;
			myNode.right.color = false;
		}

		return myNode;
	}

	void inorder(node node) {
		if (node != null) {
			inorder(node.left);
			System.out.print(node.data + " ");
			inorder(node.right);
		}
	}

	public static void main(String[] args) {

		RedBlackTree node = new RedBlackTree();

		root = node.insert(root, 10);
		root.color = false;
		root = node.insert(root, 20);
		root.color = false;
		root = node.insert(root, 30);
		root.color = false;
		root = node.insert(root, 40);
		root.color = false;
		root = node.insert(root, 50);
		root.color = false;
		root = node.insert(root, 25);
		root.color = false;

		node.inorder(root);

	}

}
