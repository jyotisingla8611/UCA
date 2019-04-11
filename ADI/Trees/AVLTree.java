package Trees;
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

		// Left Left case
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
	
	n minValue(n root) {
		n temp = root;
		while(temp.left != null) {
			temp = temp.left;
		}
		return temp;
	}
	
	n delete(n root,int key) {
		if(root == null)
			return root;
		if(key < root.data)
			root.left = delete(root.left,key);
		else if(key > root.data)
			root.right = delete(root.right,key);
		else {
			// one child or no child
			if(root.left == null || root.right == null) {
				n temp = null;
				
				if(temp == root.left) 
					temp = root.right;
				else
					temp = root.left;
				
				// no child case
				if(temp == null) {
					temp = root;
					root = null;
				}
				else {
					root = temp; // One child case
				}
				
			}
			else {
				n temp = minValue(root.right);
				root.data = temp.data;
				root.right = delete(root.right,temp.data);
			}
		}
		if(root == null)
			return root;
		
		root.height  = max(height(root.left),height(root.right))+1;
		
		int bal = getbal(root);
		//Left Left case
		if(bal > 1 && getbal(root.left) >= 0)
			return rightRotate(root);
		
		//Right Right case
		if(bal < -1 && getbal(root.right) <= 0)
			return leftRotate(root);
		
		//Right left case
		if (bal < -1 && getbal(root.right) > 0)  
        {  
            root.right = rightRotate(root.right);  
            return leftRotate(root);  
        }  
		
		//Left Right Case
		if (bal > 1 && getbal(root.left) < 0)  
        {  
            root.left = leftRotate(root.left);  
            return rightRotate(root);  
        }  
		
		return root;
	}

	public static void main(String[] args) {

		AVLTree tree = new AVLTree();

		/*tree.root = tree.insert(tree.root, 10);
		tree.root = tree.insert(tree.root, 20);
		tree.root = tree.insert(tree.root, 30);
		tree.root = tree.insert(tree.root, 40);
		tree.root = tree.insert(tree.root, 50);
		tree.root = tree.insert(tree.root, 25);
		tree.preorder(tree.root);*/
		
		tree.root = tree.insert(tree.root, 9);  
        tree.root = tree.insert(tree.root, 5);  
        tree.root = tree.insert(tree.root, 10);  
        tree.root = tree.insert(tree.root, 0);  
        tree.root = tree.insert(tree.root, 6);  
        tree.root = tree.insert(tree.root, 11);  
        tree.root = tree.insert(tree.root, -1);  
        tree.root = tree.insert(tree.root, 1);  
        tree.root = tree.insert(tree.root, 2);  
 
        System.out.println("Preorder traversal of "+  
                            "constructed tree is : ");  
        tree.preorder(tree.root);  
  
        tree.root = tree.delete(tree.root, 10);  
  
        
        System.out.println("");  
        System.out.println("Preorder traversal after "+ "deletion of 10 :");  
        tree.preorder(tree.root);  

	}

}
