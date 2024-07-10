#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high)
{
  //choose the pivot

  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);

  for(int j=low;j<=high-1;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

// The Quicksort function Implement

void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot

    int pi=partition(arr,low,high);

    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}


int main() {
  int arr[]={10,7,8,9,1,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  // Function call
  quickSort(arr,0,n-1);
  //Print the sorted array
  cout<<"Sorted Array\n";
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
/*
 FUNCTION partition(arr, low, high)
    SET pivot to arr[high]
    SET i to low - 1

    FOR j = low TO high - 1
        IF arr[j] < pivot
            INCREMENT i
            SWAP arr[i] and arr[j]

    SWAP arr[i + 1] and arr[high]
    RETURN i + 1
END FUNCTION

FUNCTION quickSort(arr, low, high)
    IF low < high
        SET pi to partition(arr, low, high)

        CALL quickSort(arr, low, pi - 1)
        CALL quickSort(arr, pi + 1, high)
END FUNCTION

FUNCTION main()
    INITIALIZE arr to {10, 7, 8, 9, 1, 5}
    SET n to size of arr

    PRINT "Given array is: "
    FOR i = 0 TO n-1
        PRINT arr[i]

    CALL quickSort(arr, 0, n - 1)

    PRINT "Sorted array is: "
    FOR i = 0 TO n-1
        PRINT arr[i]
END FUNCTION

*/

