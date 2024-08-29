#include <iostream>
#include <vector>

using namespace std;

int countZeroes(const vector<int>& arr) 
{
    int n = arr.size();
    
    // Edge case: if the array is empty
    if (n == 0) return 0;

    // Binary search to find the first occurrence of 0
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is the first occurrence of 0
        if (arr[mid] == 0 && (mid == 0 || arr[mid - 1] == 1)) 
        {
            return n - mid; // Number of 0s is the length of the array from mid to the end
        } 
        else if (arr[mid] == 1) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return 0; // If there are no zeroes in the array
}

int main() 
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array (only 0s and 1s): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int numberOfZeroes = countZeroes(arr);
    
    cout << "Number of zeroes: " << numberOfZeroes << endl;

    return 0;
}
