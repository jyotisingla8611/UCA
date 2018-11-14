package Trees;

import java.util.*;

class Nodes{
	int data;
	Nodes left;
	Nodes right;
	int size = 1;
	Nodes root;
	Nodes(int data){
		this.data = data;
		left = null;
		right = null;
	}
	
	public Nodes() {
		left = null;
		right = null;
	}

	int sizeCalc(Nodes root) {
		if(root.left == null && root.right == null)
			return 0;
		return root.size;
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
	
	root.size = 1 + sizeCalc(root.left) + sizeCalc(root.right);
	return root;
}

int rank(Nodes root , int d) {
	if(d == root.data)
		return sizeCalc(root.left);
	if(d < root.data)
		return rank(root.left,d);
	if(d > root.data)
		return 1 + sizeCalc(root.left) + rank(root.right,d);
	return d;
}
}
public class RankBst {
	public static void main(String...ar) {
		Nodes tree = new Nodes();
		
		tree.root = tree.insert(tree.root,50); 
		tree.root = tree.insert(tree.root,30);
		tree.root = tree.insert(tree.root,20);
		tree.root = tree.insert(tree.root,40);
		tree.root = tree.insert(tree.root,70);
		tree.root = tree.insert(tree.root,60);
		tree.root = tree.insert(tree.root,80);
		
		int res = tree.rank(tree,40);
		System.out.println(res);
	}
}
