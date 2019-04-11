package Algos;
public class Doubly_Linked{
    
    Node head;
     class Node{
         int data;
         Node prev;
         Node next;
         
         Node(int d){
             data = d;
         }
     }
     
     void deleteNode(Node head_ref, Node del) 
    { 
  
        // Base case 
        if (head == null || del == null) { 
            return; 
        } 
  
        // If node to be deleted is head node 
        if (head == del) { 
            head = del.next; 
        } 
  
        // Change next only if node to be deleted 
        // is NOT the last node 
        if (del.next != null) { 
            del.next.prev = del.prev; 
        } 
  
        // Change prev only if node to be deleted 
        // is NOT the first node 
        if (del.prev != null) { 
            del.prev.next = del.next; 
        } 
  
        // Finally, free the memory occupied by del 
        return; 
    } 
     void push(int d){
             Node new_Node = new Node(d);
             
             new_Node.next = head;
             new_Node.prev = null;
             
             if(head != null){
                 head.prev = new_Node;
             }
             head = new_Node;
         }
         
         void Insert_After(Node prev_node ,int d){
             if(prev_node == null)
                return ; // Node not existing
                
             Node new_node = new Node(d);
             
             new_node.next = prev_node.next;
             prev_node.next = new_node;
             new_node.prev = prev_node;
             
             if(new_node.next != null)
                new_node.next.prev = new_node;
         }
         
         void append(int d){
             Node new_node = new Node(d);
             Node last = head;
             new_node.next = null;
             if(head == null){
                 new_node.prev = null;
                 head = new_node;
                 return;
             }
             while(last.next != null)
                last = last.next;
                
             last.next = new_node;
             new_node.prev = last;
         }
         
         void insertBefore(Node head,Node next_node,int d){
             if(next_node == head){
                 push(d);
                 return;
             }
             if(next_node == null)
               return;
             Node new_node = new Node(d);
             
             new_node.prev = next_node.prev;
             next_node.prev = new_node;
             new_node.next = next_node;
             
             if(new_node.prev != null)
                new_node.prev.next = new_node;
             else
                head = new_node;
         }
         void print(){
             Node first = head;
             Node last = null;
             
             System.out.println("Node in forward direction : ");
             while(first != null){
                 System.out.print(first.data + " ");
                 last = first;
                 first = first.next;
             }
             System.out.println("\nNode in backward direction : ");
             while(last != null){
                 System.out.print(last.data + " ");
                 last = last.prev;
             }
         }

     public static void main(String []args){
        Doubly_Linked list = new Doubly_Linked();
        list.push(1);
        list.push(2);
        list.push(3);
        list.push(4);
        list.push(5);
        list.Insert_After(list.head,6);
        list.append(0);
        list.insertBefore(list.head,list.head.next.next,7);
        list.deleteNode(list.head,list.head);
        list.print();
     }
}