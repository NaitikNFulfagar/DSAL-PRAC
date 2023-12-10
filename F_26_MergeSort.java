/*
  Assume we have two input and two output tapes to perform the sorting. 
  The internal memory can hold and sort m records at a time. 
  Write a program in java for external sorting. 
  and out time complexity.  
*/
import java.util.Scanner;

class F_26_MergeSort {

    public static void merge(int arr[], int a, int mid, int z) {
  
        int s1 = mid - a+1;
        int s2 = z - mid;
    
        int M1[] = new int[s1];
        int M2[] = new int[s2];
    
        for (int i = 0; i < s1; i++)
            M1[i] = arr[a + i];
        for (int j = 0; j < s2; j++)
            M2[j] = arr[mid + 1 + j];
    
        int i, j, k;
        i = 0;
        j = 0;
        k = a;
    
        while (i < s1 && j < s2) 
        {
            if (M1[i] <= M2[j]) 
            {
                arr[k++] = M1[i++];
            }
            else 
            {
                arr[k++] = M2[j++];
            }
        }
        
        while (i < s1) 
        {
            arr[k++] = M1[i++];
        }
  
        while (j < s2) 
        {
            arr[k++] = M2[j++];
            
        }
    }
  
    public static void mergeSort(int arr[], int a, int z) 
    {
        if (a < z) 
        {
            int mid = (a + z) / 2;
    
            mergeSort(arr, a, mid);
            mergeSort(arr, mid + 1, z);
            merge(arr, a, mid, z);
        }
    }
  
    public static void main(String args[]) 
    {   
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter No. Elements to be Entered : ");
        int n = sc.nextInt();
        System.out.print("Enter Elements of Array : ");
        int arr[] = new int[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i]=sc.nextInt();
        }
        sc.close();
        mergeSort(arr, 0, n - 1);
        
        //Printing
        System.out.println("Sorted array:");
        
        for (int i = 0; i < n; ++i)
        {
            System.out.print(arr[i] + " ");
        }
    }
  }

//Coded By Naitik Fulfagar