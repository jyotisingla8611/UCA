class Nodes{
		int data;
		Nodes left;
		Nodes right;
		
		Nodes(int data){
			this.data = data;
			left = null;
			right = null;
		}
	}

public class BinarySearchTree {
	
			Nodes root;
		
		BinarySearchTree(){
			root = null;
		}
		Nodes insert(Nodes root,int key) {
			
			if(root == null) {
				root = new Nodes(key);
				return root;
			}
			
			if(key < root.data)
				root.left = insert(root.left,key);
			else
				root.right = insert(root.right,key);
			
			return root;
		}
		
		 void inorderRec(Nodes root) { 
		        if (root != null) { 
		            inorderRec(root.left); 
		            System.out.println(root.data); 
		            inorderRec(root.right); 
		        } 
		    } 
		 
		 Nodes search(Nodes root,int key) {
			 if(root.data == key || root == null)
				 return root;
			 if(root.data > key)
				 return search(root.left,key);
			 else
				 return search(root.right,key);
				 
		 }
	
	public static void main(String[] args) {
		
		BinarySearchTree tree = new BinarySearchTree();
		
		//Nodes root = null;
		tree.root = tree.insert(tree.root,50); 
		tree.root = tree.insert(tree.root,30);
		tree.root = tree.insert(tree.root,20);
		tree.root = tree.insert(tree.root,40);
		tree.root = tree.insert(tree.root,70);
		tree.root = tree.insert(tree.root,60);
		tree.root = tree.insert(tree.root,80);
		
		tree.inorderRec(tree.root);
		
		System.out.println("Searching an element we get : " + tree.search(tree.root,50));
	}
	

}

