/*
    Implement the Heap/Shell sort algorithm implemented in Java
    demonstrating heap/shell data structure with modularity of programming language  
*/

import java.util.Scanner;

public class E_21_Shell{
    public static void shellSort(int[] arr){
        int n = arr.length;
        int j;
        
        for(int gap=n/2; gap>0; gap/=2)
        {
            for(int i=gap; i<n; i++)
            {
                int temp = arr[i];
                for( j=i; j>=gap && arr[j-gap]>temp; j-=gap)
                {
                    arr[j] = arr[j-gap];
                }
                arr[j] = temp;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements: ");
        for(int i=0; i!=n; i++)
        {
            arr[i] = sc.nextInt();
        }

        shellSort(arr);

        System.out.println("Sorted List: ");
        for(int i=0;i<n;i++){
            System.out.print(arr[i] + "  ");
        }

        sc.close();

    }
}
//Coded By Naitik Fulfagar