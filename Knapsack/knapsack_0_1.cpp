#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack_0_1(int W, int wt[], int values[], int n)
{
    if (n == 0 || W == 0)
        return 0;
 
    if (wt[n - 1] > W)
        return knapSack_0_1(W, wt, values, n - 1);
 
    else
        return max(
            values[n - 1]
                + knapSack_0_1(W - wt[n - 1],
                           wt, values, n - 1),
            knapSack_0_1(W, wt, values, n - 1));
}
 
// Driver code
int main()
{   
    int n = 4;
    int values[n];
    int weights[n] ;
    int W = 40;
    cout<<"Enter "<< n <<" values :";
    for (int i=1;i<=4;i++){
        cin>>values[i];
    }
    cout<<"Enter "<< n <<" corresponding weights :";
    for (int i=1;i<=4;i++){
        cin>>weights[i];
    }
    cout <<"Highest Profit achieved : "<< knapSack_0_1(W, weights, values, n);
    return 0;
}