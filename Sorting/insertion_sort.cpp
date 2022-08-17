#include <iostream>
using namespace std;
int main(){
    int arr [10];
    int newarr [10];
    int n;
    cout<<"Enter number of array elements (less than 10): ";
    cin >> n;
    cout<<"Enter the array elements : ";
    for (int i = 0; i < n ; i++ ){
        cin>>arr[i];
    }
    for (int j=1; j<n; j++){
        int key = arr[j];
        int i = j-1;
        while (i>=0 && arr[i] > key){
            arr[i+1] = arr[i];
            i=i-1;
        }
        arr[i+1] = key;
    }
    for (int i = 0; i < n ; i++ ){
        cout<<arr[i] << " ";
    }
    
    
}