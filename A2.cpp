#include <iostream>
#include <vector>

using namespace std;

void moveZeroesToEnd(vector<int>& arr) 
{
    int count = 0; // Count of non-zero elements

    // Traverse the array. If element encountered is non-zero, then
    // replace the element at index 'count' with this element
    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i] != 0) 
        {
            arr[count++] = arr[i]; // here count is incremented
        }
    }

    // Now all non-zero elements have been shifted to the front and 
    // 'count' is set as index of first 0. Make all elements 0 from 
    // count to end.
    while (count < arr.size()) 
    {
        arr[count++] = 0;
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveZeroesToEnd(arr);

    cout << "Array after moving zeroes to the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
