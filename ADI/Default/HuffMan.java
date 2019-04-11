

import java.util.PriorityQueue;
import java.util.*;
class HuffNode{
    int freq;
    char ch;
    HuffNode right;
    HuffNode left;
}

class HuffComparator implements Comparator<HuffNode>{
    public int compare(HuffNode x , HuffNode y){
        return x.freq - y.freq;
    }
}

public class HuffMan{
    
    void decode(HuffNode rt , String s){
        int n = s.length();
        int i = 0;
        while(i < n){
            if(rt.left == null  && rt.right == null &&Character.isLetter(rt.ch))
               System.out.print(rt.ch);
            if(s.charAt(i) == '1')
                rt = rt.left;
            else
                rt = rt.right;
            i++;
        }
    }
    void printPattern(HuffNode rt , String s,HashMap<Character,String>h1){
        if(rt.left == null && rt.right == null && Character.isLetter(rt.ch)){
            h1.put(rt.ch,s);
            return;
        }
        printPattern(rt.left , s + "0",h1);
        printPattern(rt.right , s + "1",h1);
    }
  
    @SuppressWarnings("rawtypes")
	HashMap getFrequency(String s){
        int len  = s.length();
        HashMap<Character,Integer>hm = new HashMap<Character,Integer>();
        for(int i = 0 ;i < len ; i ++ ){
            char c = s.charAt(i);
            if(c != ' '){
                if(hm.containsKey(c)== true){
                    hm.put(c,hm.get(c) + 1);
                }else{
                    hm.put(c,1);
                } 
            }
        }
        
        return hm;
    }
    
    @SuppressWarnings({ "rawtypes", "unchecked" })
	public static void main(String...args){
        HuffMan huff = new HuffMan();
        @SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
        System.out.println("Enter the String");
        String str = scan.nextLine();
        HashMap<Character,Integer>map = new HashMap<Character,Integer>();
        map = huff.getFrequency(str);
        int length = map.size();
        int[] frequency = new int[length];
        char[] array = new char[length];
        int j = 0;
        for (Map.Entry entry : map.entrySet()) { 
            array[j] = (Character)entry.getKey() ;
            frequency[j] = (Integer)entry.getValue();
            j++;
        }
        
        
        PriorityQueue<HuffNode> que = new PriorityQueue<HuffNode>(length,new HuffComparator());
        
        for(int i = 0 ; i < length ; i++){
            HuffNode temp = new HuffNode();
            if(array[i] != ' '){
                temp.ch = array[i];
                temp.freq = frequency[i];
                temp.right = null;
                temp.left = null;
                que.add(temp);
            }
        }
        
        HuffNode root = null;
        
        while(que.size() > 1){
            HuffNode x,y;
            HuffNode z = new HuffNode();
            x = que.peek();
            que.poll();
            y = que.peek();
            que.poll();
            z.freq = y.freq + x.freq;
            z.ch = '*';
            z.left = x;
            z.right = y;
            root = z;
            que.add(z);
        }
        
        HashMap<Character,String>mapCode = new HashMap<Character,String>();
        huff.printPattern(root,"",mapCode);
        for (Map.Entry entry : mapCode.entrySet()) { 
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
        
        System.out.println("Enter a word from above string to encode it : ");
        String word = scan.next();
        String result = "";
        for(int i = 0 ;i < word.length() ;i++){
            result = result + mapCode.get(word.charAt(i));
        }
        
        System.out.println("Word : " + word + " is encoded as : " + result);
        
        System.out.println("Enter encoded word to decode it : ");
        String enWord = scan.next();
        huff.decode(root,enWord);
    }
}