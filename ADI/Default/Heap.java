class P
{
    private int[] a;
    private int size;
    P()
    {
        a=new int[100];
        size=0;
    }
    int parent(int i)
    {
        return i/2;
    }
    int left(int i)
    {
        return 2*i;
    }
    int right(int i)
    {
        return 2*i+1;
    }
    void swap(int[] a,int i)
    {
        int temp=a[i];
        a[i]=a[parent(i)];
        a[parent(i)]=temp;
    }
    void swim(int[] a,int index)
    {
        if(index==0)
            return;
        else if(a[index]>=a[parent(index)])
            return;
        else
        {
            swap(a,index);
            swim(a,parent(index));
        }
    }
    void sink(int i)
    {
        int smallest=i;
        if(left(i)<size && a[left(i)]<a[i])
            smallest=left(i);
        if(right(i)<size && a[right(i)]<a[smallest])
            smallest=right(i);
        if(smallest!=i)
        {
            int temp2 = a[i];
            a[i] = a[smallest];
            a[smallest] = temp2;
            sink(smallest);
        }
    }
    void enqueue(int data)
    {
        a[size] = data;
        swim(a,size);
        size++;
    }

    void dequeue(int i)
    {
        a[i] = Integer.MIN_VALUE;

        swim(a,i);

        int temp1 = a[0];
        a[0] = a[size-1];
        a[size-1] = temp1;

        size--;

        sink(0);
    }

    void display()
    {
        int i;
        for(i=0;i<size;i++)
        {
            System.out.println(a[i]);
        }
    }
}
public class Heap
{
    public static void main(String args[])
    {
        P p=new P();
        p.enqueue(0);
        p.enqueue(3);
        p.enqueue(4);
        p.enqueue(2);
        p.enqueue(1);
        p.enqueue(5);
        p.dequeue(1);  //parameter is index inside it.
        p.display();
    }
}