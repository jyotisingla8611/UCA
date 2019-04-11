package Trees;
import java.util.*;
public class SearchEngine{
    
    static final int alpha_size = 26;
    
    static class TrieNode{
        TrieNode [] child = new TrieNode[alpha_size];
        boolean isEnd ;
        int weight;
        
        TrieNode(){
            for(int i = 0;i<alpha_size;i++)
                child[i] = null;
            isEnd = false;
            weight = 0;
        }
    }
    
    static TrieNode root;
    
    static int max(int a,int b){
        return (a > b ? a : b);
    }
    static void insert(String str ,int wt){
        int len = str.length();
        int i,ind;
        TrieNode temp = root;
        for(i = 0;i<len;i++){
            ind = str.charAt(i) - 'a';
            if(temp.child[ind] == null){
                temp.child[ind] = new TrieNode();
                temp.child[ind].weight = wt;
            }
            else{
                int m = max(temp.child[ind].weight,wt);
                temp.child[ind].weight = m;
            }
            temp = temp.child[ind];    
        }
        temp.isEnd = true;
    }
    
    static int result(String s){
        int len = s.length();
        int i,ind;
        TrieNode temp = root;
        int r= 0;
        for(i = 0;i<len;i++){
            ind = s.charAt(i) - 'a';
            temp = temp.child[ind];
            r = temp.weight; 
        }
        return r;
    }
    static boolean search(String str){
        int len = str.length();
        int i,ind;
        TrieNode temp = root;
        for(i = 0;i<len;i++){
            ind = str.charAt(i)- 'a';
            if(temp.child[ind] == null)
                return false;
            temp = temp.child[ind];    
        }
        return true;
    }
    @SuppressWarnings("resource")
	public static void main(String...args){
        int n,q;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        q = scan.nextInt();
        root = new TrieNode();
        String s;
        int wt;
        while(n != 0){
            s = scan.next();
            wt = scan.nextInt();
            insert(s,wt);
            n--;
        }
        
        while(q != 0){
            s = scan.next();
            boolean res = search(s);
            if(res == true){
              int ans = result(s);
              System.out.println(ans);
            }
            else{
                System.out.println("-1");
            }
            q--;
        }
        
    }
}