#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool isValid(int tasks[], int N, int D, int maxWork) {
    int days = 1, currentWork = 0;
    for (int i = 0; i < N; i++) {
        if (currentWork + tasks[i] > maxWork) {
            days++;
            currentWork = tasks[i];
            if (days > D) return false;
        } else {
            currentWork += tasks[i];
        }
    }
    return days <= D;
}

int minWorkPerDay(int tasks[], int N, int D) {
    int left = *max_element(tasks, tasks + N);
    int right = accumulate(tasks, tasks + N, 0);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValid(tasks, N, D, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int N, D;
    cin >> N >> D;
    int tasks[N];
    for (int i = 0; i < N; i++) {
        cin >> tasks[i];
    }
    cout << minWorkPerDay(tasks, N, D) << endl;
    return 0;
}
