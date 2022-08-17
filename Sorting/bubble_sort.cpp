#include<iostream>
using namespace std;

int main(){
    int arr[] = {3, 2, 1, 4, 5, 6};
    int n = sizeof(arr)/sizeof(int);
    for (int i = 0;i<n;i++){
        for (int j = i+1;j<n-i-1;j++){
            if (arr[i]>arr[j]){
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    cout<<"\nAfter bubble sort operation, the array is:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}