#include<iostream>
using namespace std;
int main(){
    int arr [] = {4, 5, 6, 2, 4, 1};
    int n = sizeof(arr)/sizeof(int);
    for (int i=0;i<n-1;i++){
        int min_index = i;
        for (int j=i+1;j<n;j++){
            if (arr[min_index] > arr[j]){
                min_index = j; //finds the minimum at each iteratin and brings them in the front of array
            }
        }
        arr[i] = arr[i]+arr[min_index];
        arr[min_index] = arr[i]-arr[min_index];
        arr[i] = arr[i]-arr[min_index];
    }
    cout<<"\nThe array after selection sort:\n";
    for (int k = 0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}