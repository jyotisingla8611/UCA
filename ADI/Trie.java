
public class Trie {

	static final int alpha_size = 26;
	
	static class TrieNode{
		TrieNode[] child = new  TrieNode[alpha_size];
		boolean isEndOfword;
		
		TrieNode() {
			for(int i=0;i<alpha_size;i++)
				child[i] = null;
			isEndOfword = false;
		}
	};
	
	static TrieNode root;
	
	static void insert(String str) {
		int i;
		int len = str.length();
		int ind;
		TrieNode temp = root;
		for(i=0;i<len;i++) {
			ind = str.charAt(i) - 'a';
			if(temp.child[ind] == null)
				temp.child[ind] = new TrieNode();
			temp = temp.child[ind];
		}
		temp.isEndOfword = true;
	}
	
	static boolean search(String str) 
    { 
        int i; 
        int len = str.length(); 
        int ind; 
        TrieNode temp = root;
        for (i = 0; i < len; i++) 
        { 
            ind = str.charAt(i) - 'a'; 
       
            if (temp.child[ind] == null) 
                return false; 
       
            temp = temp.child[ind]; 
        } 
       
        return (temp != null && temp.isEndOfword); 
    } 
	
	public static void main(String[] args) {
		
		root = new TrieNode();
		insert("jyoti");
		insert("rajni");
		
		if(search("jyoti") == true)
			System.out.println("Found");
		else
			System.out.println("Not Found");
	}

}
