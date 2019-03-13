import java.util.*;

public class Main {
     private Node root;
        
        private class Node {
            
            private final Integer key;
            private Node right;
            private Node left;
            private int N;
            
            public Node(Integer key) {
                this.key = key;
                N = 1;
            }
        }
        public boolean isEmpty() {
            return size() == 0;
        }
        
        public int size() {
            return sizeOf(root);
        }
        
        private int sizeOf(Node x) {
            return x == null ? 0 : x.N;
        }
    
        public Integer get(int key) {
            Node x = get(root, key);
            return x == null ? null : x.key;
        }
        
        private Node get(Node x, Integer key) {
            if (x == null) {
                return null;
            }
            int cmp = key.compareTo(x.key);
            if (cmp == 0) {
                return x;
            }
            if (cmp < 0) {
                return get(x.left, key);
            }
            return get(x.right, key);
        }

        public void insert(int key) {
     // Node temp = root;
        root = insert(root, key);
      }

      public Node insert(Node x, int key) {
        // if(get(x,key)==null){
        if (x == null) {
          x = new Node(key);
          return x;
        }
        if (key > x.key) {
          x.right = insert(x.right, key);
        } else
          x.left = insert(x.left, key);

        x.N = 1 + sizeOf(x.left) + sizeOf(x.right);

        //System.out.println(x.N + " size" + x.key);
        return x;
      }
      /*
       * return x; }
       */

      public int search(Node root, int key) {
        if (root == null)
          return -1;
        if (root.key == key)
          return root.key;
        if (root.key > key)
          return search(root.left, key);
        else
          return search(root.right, key);

      }

      public Integer getRank(int key) {
        // complete this function
        // if(search(root,key) == -1)
        // return -1;
        // Integer r = getRank(root,key);
        // Node temp = root;
        if (get(key) == null)
          return -1;
        Integer x = getRank(root, key);
        return x;
      

      }

      public Integer getRank(Node x, int key) {
        if (x == null)
          return -1;
        if (key < x.key)
          return getRank(x.left, key);
        else if (key == x.key)
          return sizeOf(x.left);
        else
          return 1 + sizeOf(x.left) + getRank(x.right, key);
      }

      public static void inorder(Node root) {
        if (root == null)
          return;
        inorder(root.left);
        System.out.print(root.key + " ");
        inorder(root.right);
      }

      @SuppressWarnings("resource")
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main bst = new Main();
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
          bst.insert(in.nextInt());
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
          System.out.println(bst.getRank(in.nextInt()));
        }
        // inorder(bst.root);
      }
    }