package Trees;

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
	}
	
	static TrieNode root;
	
	// INSERTION
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
	//SEARCHING
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
		
	//DELETION
	static boolean delete(TrieNode curr,String key,int index) {
	     if(key.length()==index)
	     {
	         if(curr.isEndOfword == false)
	         {
	             return false;   //if word is not present
	         }
	         curr.isEndOfword = false;  //if word is found then make its isEndOfword=false

	         for(int i=0;i<26;i++)  //in case of "the" and "there"
	         {
	             if(curr.child[i]!=null)
	             {
	                 return false;
	             }
	         }
	         return true;
	     }
	     else
	     {
	         int i=key.charAt(index)-'a';
	         if(curr.child[i] == null)
	         {
	             return false;
	         }
	         TrieNode curr1=curr.child[i];
	         boolean b=delete(curr1,key,index+1);
                          
	        //deletion of character begins.
	         if(b)
	         {
	             @SuppressWarnings("unused")
				TrieNode temp = curr.child[i];  //picks the last char of there,removes it.
	             curr.child[i]=null;
	             if(curr.isEndOfword)   //curr points to what?
	                 return false;
	             else
	             {
	                 for(int p=0;p<26;p++)
	                 {
	                     if(curr.child[p]!=null)
	                         return false;
	                 }
	                 return true;
	             }
	         }
	     }
	     return false;
	  }

	public static void main(String[] args) {
		
		root = new TrieNode();
		insert("jyoti");
		insert("rajni");
		insert("sahil");
		insert("rahul");
		insert("jyot");
		
		if(search("jyoti") == true)
			System.out.println("Found");
		else
			System.out.println("Not Found");
		
	    boolean res = delete(root,"jyoti",0);
		@SuppressWarnings("unused")
		boolean res1 = delete(root,"jyot",0);
	    System.out.println("Delete Status " + res  + "  ");
	    
	    if(search("jyot") == true)
			System.out.println("Found");
		else
			System.out.println("Not Found");
		
	}
	
}
