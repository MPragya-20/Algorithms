#include<iostream>
using namespace std;

int fractional_knapsack(int profit[], int weight[], int W, int n){
    int p[n];
    float added_weight = 0;
    double final_profit = 0.0;
    for (int i = 0;i<n;i++){
        p[i] = profit[i]/weight[i];
    }
    
    for (int i = 0;i<n;i++){
        if (added_weight+weight[i] <= W){
            added_weight += weight[i];
            final_profit += profit[i];
        }
        else{
            int weight_left = W-added_weight;
            added_weight += weight_left; 
            final_profit += profit[i]* ((double)weight_left/ weight[i]); // fractional
            break;
        }
    }
    return (final_profit);
}
int main(){
    int W = 60;
    int n = 4;
    int profits[] = {100,280,120,120};
    int weights[] = {10,40,20,24};
    cout<<"\nThe final profit : "<< fractional_knapsack(profits, weights, W, n);

}