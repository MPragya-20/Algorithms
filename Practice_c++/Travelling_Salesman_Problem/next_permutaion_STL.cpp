#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3] = {1, 2, 3};

    sort(arr, arr+3);

    do{
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    }while(next_permutation(arr, arr+3));

    cout<<"\nAfter the loop\n";
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;

}