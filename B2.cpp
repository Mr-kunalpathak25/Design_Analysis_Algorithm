#include <iostream>
using namespace std;

int maxProfit(int prices[], int n) 
{
    int profit = 0;
    
    for (int i = 1; i < n; i++) 
    {
        if (prices[i] > prices[i - 1]) 
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    
    return profit;
}

int main() 
{
    int n;
    
    cout << "Enter the number of days: ";
    cin >> n;
    
    int prices[n];
    cout << "Enter the stock prices for each day: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> prices[i];
    }
    
    int result = maxProfit(prices, n);
    
    cout << "The maximum profit is: " << result << endl;
    
    return 0;
}
