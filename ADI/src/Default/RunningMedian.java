package Default;


import java.util.*;
public class RunningMedian {
  void runningArr(int[]arr){
      int len = arr.length;
      double[] res = new double[len];
      res = getMedian(arr);
      for(int i = 0;i<len;i++)
        System.out.println(res[i]);
  }
  
  double[] getMedian(int[] arr){
      int len = arr.length;
      double[] res = new double[len];
      res[0] = (double)arr[0];
      for(int i = 1;i<len;i++){
        int[] temp = new int[i+1];
          for(int j = 0 ; j<=i;j++){
              temp[j] = arr[j];
          }
          Arrays.sort(temp);
          int k = i + 1;
          int mid = k/2;
          if(k % 2 == 0){
              res[i] = ((double)temp[mid-1] + (double)temp[mid])/2;
          }
          else{
              res[i] = (double)temp[mid];
          }
      }
      return res;
  }
      public static void main(String []args)
    {
        RunningMedian obj = new RunningMedian();
        Scanner sc = new Scanner(System.in);
        int num;
        num = sc.nextInt();
        int [] arr = new int[num];
        
        for(int i=0; i<num;i++)
        {
            arr[i] = sc.nextInt();
        }
        obj.runningArr(arr);
        sc.close();
        
        
    }
}