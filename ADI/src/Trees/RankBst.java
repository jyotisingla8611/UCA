package Trees;

class Nodes11{
	int data;
	Nodes11 left;
	Nodes11 right;
	int size = 1;
	Nodes11 root = null;
	Nodes11(int data){
		this.data = data;
		left = null;
		right = null;
	}
	
	Nodes11() {
		left = null;
		right = null;
	}

	int sizeCalc(Nodes11 root) {
		if(root == null)
			return 0;
		return root.size;
	}

Nodes11 insert(Nodes11 root,int key) {
	
	if(root == null) {
		root = new Nodes11(key);
		return root;
	}
	if(key < root.data)
		root.left = insert(root.left,key);
	else
		root.right = insert(root.right,key);
	
	root.size = 1 + sizeCalc(root.left) + sizeCalc(root.right);
	return root;
}

int rank(Nodes11 root , int d) {
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
		Nodes11 tree = new Nodes11();
		
		tree.root = tree.insert(tree.root,50); 
		tree.root = tree.insert(tree.root,30);
		tree.root = tree.insert(tree.root,20);
		tree.root = tree.insert(tree.root,40);
		tree.root = tree.insert(tree.root,70);
		tree.root = tree.insert(tree.root,60);
		tree.root = tree.insert(tree.root,80);
		
		int res = tree.rank(tree.root,60);
		System.out.println(res);
	}
}
