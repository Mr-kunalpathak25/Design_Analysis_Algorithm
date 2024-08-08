#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array (only 0s and 1s): ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    for(int i = mid + 1; i < n; i++) {
        count++;
    }

    cout << "Number of zeros are: " << count;
    return 0;
}
