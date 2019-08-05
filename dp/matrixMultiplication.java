import java.util.*;
import java.lang.*;
import java.io.*;

class MatrixMultiplication
{
    // Recursive solution
    static int matrixChainOrder(int arr[], int i, int j){
        if(i==j)
            return 0;

        int min = Integer.MAX_VALUE;
        for(int k=i;k<j;k++){
            int count = matrixChainOrder(arr, i, k) + matrixChainOrder(arr, k+1, j) +
                        arr[i-1]*arr[k]*arr[j];

            min = Math.min(count,min);
        }
        return min;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		int arr[] = new int[] {1, 2, 3, 4, 3}; 
        int n = arr.length; 
        System.out.println("Minimum number of multiplications is "+ 
                           matrixChainOrder(arr, 1, n-1)); 
	}
}