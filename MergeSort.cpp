#include<iostream>
using namespace std;

// Function to merge two halves
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to sort an array using merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
/*
FUNCTION merge(arr, l, m, r)
    n1 = m - l + 1
    n2 = r - m

    Create temporary arrays L[0..n1-1] and R[0..n2-1]

    FOR i = 0 TO n1-1
        L[i] = arr[l + i]

    FOR j = 0 TO n2-1
        R[j] = arr[m + 1 + j]

    i = 0 // Initial index of first subarray
    j = 0 // Initial index of second subarray
    k = l // Initial index of merged subarray

    WHILE i < n1 AND j < n2
        IF L[i] <= R[j]
            arr[k] = L[i]
            i = i + 1
        ELSE
            arr[k] = R[j]
            j = j + 1
        k = k + 1

    WHILE i < n1
        arr[k] = L[i]
        i = i + 1
        k = k + 1

    WHILE j < n2
        arr[k] = R[j]
        j = j + 1
        k = k + 1
END FUNCTION

FUNCTION mergeSort(arr, l, r)
    IF l < r
        m = l + (r - l) / 2

        CALL mergeSort(arr, l, m)
        CALL mergeSort(arr, m + 1, r)

        CALL merge(arr, l, m, r)
END FUNCTION

FUNCTION main()
    INITIALIZE arr to {12, 11, 13, 5, 6, 7}
    SET arr_size to size of arr

    PRINT "Given array is: "
    FOR i = 0 TO arr_size-1
        PRINT arr[i]

    CALL mergeSort(arr, 0, arr_size - 1)

    PRINT "Sorted array is: "
    FOR i = 0 TO arr_size-1
        PRINT arr[i]
END FUNCTION
*/
