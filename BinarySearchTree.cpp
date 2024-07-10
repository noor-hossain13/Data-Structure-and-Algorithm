#include<iostream>
using namespace std;

int binarysearch(int arr[], int l, int r, int tar)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == tar)
            return mid;

        if (arr[mid] < tar)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 7, 8, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout <<"Values are :";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    cout << "Which value do you want to search: ";
    int s;
    cin >> s;

    int x = binarysearch(arr, 0, n-1, s);

    if (x != -1)
        cout << "Position is " << x << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}
