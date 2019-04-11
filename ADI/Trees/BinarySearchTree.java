package Trees;

class Nodes {
	int data;
	Nodes left;
	Nodes right;

	Nodes(int data) {
		this.data = data;
		left = null;
		right = null;
	}
}

public class BinarySearchTree {

	Nodes root;

	BinarySearchTree() {
		root = null;
	}

	//INSERTION
	
	Nodes insert(Nodes root, int key) {

		if (root == null) {
			root = new Nodes(key);
			return root;
		}

		if (key < root.data)
			root.left = insert(root.left,key);
		else
			root.right = insert(root.right,key);

		return root;
	}

	//INORDER TRAVERSAL
	
	void inorderRec(Nodes root) {
		if (root != null) {
			inorderRec(root.left);
			System.out.print(root.data + " ");
			inorderRec(root.right);
		}
	}

	//SEARCHING
	Nodes search(Nodes root, int key) {
		if (root.data == key || root == null)
			return root;
		if (root.data > key)
			return search(root.left, key);
		else
			return search(root.right, key);
	}
	
	int max_val(Nodes root) {
		while(root.right != null) {
			root = root.right;
		}
		return root.data;
	}
	
	int min_val(Nodes root) {
		while(root.left != null) {
			root = root.left;
		}
		return root.data;
	}
	
	//DELETION
	Nodes delete(Nodes root,int item) {
		if(root == null)
			return null;
		if(item > root.data)
			root.right = delete(root.right,item);
		else if(item < root.data)
			root.left = delete(root.left,item);
		else {
			if(root.left == null)
				return root.right;
			else if(root.right == null)
				return root.left;
			else {
				/*root.data = max_val(root.left);
				root.left = delete(root.left,root.data);
				*/
				 root.data = min_val(root.right);
				 root.right = delete(root.right,root.data);
				 
			}
		}
		return root;
	}

	int searchIndex(int[]arr,int val,int strt,int end) {
		for(int i = strt; i <end;i++) {
			if(arr[i] > val)
				return i;
		}
		return -1;
	}
	
	Nodes BstFromPre(int[]pre,int index,int strt,int end) {
		if(strt > end)
			return null;
		Nodes root = new Nodes(pre[index]);
		index++;
		if(strt == end)
			return root;
		int ind = searchIndex(pre,root.data,strt,end);
		root.left = BstFromPre(pre,index,strt,ind-1);
		root.right = BstFromPre(pre,index,ind,end);
		return root;
	}
	
	/*int isBST(Nodes node)  
	{  
	  if (node == null)  
	    return(1);  
	      
	   false if the max of the left is > than us 
	  if (node.left!=null && max_val(node.left) > node.data)  
	    return(0);  
	      
	   false if the min of the right is <= than us 
	  if (node.right!=null && min_val(node.right) < node.data)  
	    return(0);  
	    
	   false if, recursively, the left or right is not a BST 
	  if (isBST(node.left) == 0 || isBST(node.right) == 0)  
	    return(0);  
	      
	   passing all that, it's a BST 
	  return(1);  
	}*/
	
	//TO CHECK VALID BST 
	public boolean isBST(Nodes root){
        return isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    private boolean isBST(Nodes root, int min, int max){
        if(root == null){
            return true;
        }
        if(root.data <= min || root.data > max){
            return false;
        }
        return isBST(root.left, min, root.data) && isBST(root.right, root.data, max);
    }
	
    // LOWEST COMMON ANCESTOR
	Nodes lca(Nodes node, int n1, int n2)  
    { 
        if (node == null) 
            return null; 
   
        // If both n1 and n2 are smaller than root, then LCA lies in left 
        if (node.data > n1 && node.data > n2) 
            return lca(node.left, n1, n2); 
   
        // If both n1 and n2 are greater than root, then LCA lies in right 
        if (node.data < n1 && node.data < n2)  
            return lca(node.right, n1, n2); 
   
        return node; 
    } 
	/*treenode*func(treenode*root,int n1,int n2)
	 {
	     if(root==NULL)                   ///LCA CAN BE DONE AS SO : 
	        return root;
	    if(root->val==n1||root->val==n2)
	        return root;
	    treenode*l = func(root->left,n1,n2);
	    treenode*r = func(root->right,n1,n2);
	    if(l&&r)
	        return root;
	    if(l)
	        return l;
	    return r;
	 }*/
	
	int kth(Nodes root,int k,int count) {
		if(root == null)
			return 0;
		if(count == k)
			return root.data;
		@SuppressWarnings("unused")
		int left = kth(root.left,k,count++);
		@SuppressWarnings("unused")
		int right = kth(root.right,k,count++);
		return root.data;
	}
	// CEILING FUNCTION
	int Ceil(Nodes root, int key) { 
        if(root == null)
        	return -1;
        if(root.data == key)
        	return root.data;
        if(root.data < key)
        	return Ceil(root.right,key);
        int temp = root.data;
        int expected = Ceil(root.left,key);
        if(expected != -1)
        	return expected;
        else
        	return temp;
    } 
	
	
	// FLOOR VALUE
	int Floor(Nodes root,int key) {
		if(root == null)
        	return -1;
        if(root.data == key)
        	return root.data;
        if(root.data > key)
        	return Floor(root.left,key);
        int temp = root.data;
        int expected = Floor(root.right,key);
        if(expected != -1)
        	return expected;
        else
        	return temp;
	}
	
	public static void main(String[] args) {

		BinarySearchTree tree = new BinarySearchTree();

		// Nodes root = null;
		tree.root = tree.insert(tree.root, 50);
		tree.root = tree.insert(tree.root, 30);
		tree.root = tree.insert(tree.root, 20);
		tree.root = tree.insert(tree.root, 40);
		tree.root = tree.insert(tree.root, 70);
		tree.root = tree.insert(tree.root, 60);
		tree.root = tree.insert(tree.root, 80);
        System.out.println("The tree formed is as : ");
		tree.inorderRec(tree.root);
		System.out.println("");
		Nodes res = tree.search(tree.root, 50);
		System.out.println("Searching an element we get : " + res.data);
		System.out.println("Maximum Value in a tree is as : " + tree.max_val(tree.root));
		System.out.println("Minimum Value in a tree is as : " + tree.min_val(tree.root));
	
		Nodes afterDeletion = tree.delete(tree.root,40);
		System.out.println("After Deletion the tree formed is as : ");
		tree.inorderRec(afterDeletion);
		System.out.println("");
	/*	
		int []pre = {10,5,1,7,40,50};
		Nodes resultTree = tree.BstFromPre(pre, 0, 0, pre.length-1);
		System.out.println("The tree formed using the given pre order is as : ");
		tree.inorderRec(resultTree);
		*/
		Nodes lc = tree.lca(tree.root, 20,70);
		System.out.println("The Lowest common Ancestor is as " + lc.data);
	
		if(tree.isBST(tree.root) == true)
			System.out.println("Tree is Valid BST " );
		else
			System.out.println("Tree is Not Valid BST " );
		
		System.out.println("Ceil Value of a 30 is :  " + tree.Ceil(tree.root, 39));
		System.out.println("Floor Value of a 30 is :  " + tree.Floor(tree.root, 30));
		System.out.println("Kth smallest " + tree.kth(tree.root, 2, 0));
	}

}
