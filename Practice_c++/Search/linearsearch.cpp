#include <iostream>
using namespace std;

int linear_(int arr[],int n, int no){
    for (int i = 0; i<n ; i++){
        if (arr[i] == no){
            return (i);
        }
    }
    return -1;
}

int main(){
    int n,number;
    int A[15];
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"\nEnter array elements :\n";
    for (int i = 0;i<n;i++){
        cin>>A[i];
    }
    cout<<"\nThe array elements are as follows\n";
    for (int i = 0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<"\nEnter the number to be searched for : ";
    cin>>number;
    int result = linear_(A,n,number);
    if (result == -1){
        cout<<"\nThe number is not found !!\n";
    }
    else{
        cout<<"\nThe number is found at index: "<<result;
    }
}
