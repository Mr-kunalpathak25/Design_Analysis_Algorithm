#include <iostream>
#include <algorithm>

using namespace std;

struct Shop 
{
    int start, end;
};

bool compare(Shop s1, Shop s2) 
{
    return s1.end < s2.end;
}

int maxShopsVisited(int n, int S[], int E[], int K) 
{
    Shop shops[n];

    for (int i = 0; i < n; i++) 
    {
        shops[i] = {S[i], E[i]};
    }

    sort(shops, shops + n, compare);

    int persons[K] = {0};
    int shopCount = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < K; j++) 
        {
            if (persons[j] <= shops[i].start) 
            {
                persons[j] = shops[i].end;
                shopCount++;
                break;
            }
        }
    }

    return shopCount;
}

int main() 
{
    int n, K;

    cout << "Enter the number of shops: ";
    cin >> n;

    int S[n], E[n];

    cout << "Enter the start times of the shops: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> S[i];
    }

    cout << "Enter the end times of the shops: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> E[i];
    }

    cout << "Enter the number of persons: ";
    cin >> K;

    int result = maxShopsVisited(n, S, E, K);

    cout << "Maximum number of shops that can be visited: " << result << endl;

    return 0;
}
