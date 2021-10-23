#include <iostream>
using namespace std;

void insert_sort(int A[], int n){
    for (int i = 1; i<n ;i++){
        int key = A[i];
        int j = i - 1;
        while ( j>= 0 && A[j] > key){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = key;
    }
    
}
int main(){
    int n,element;
    int Array[20];
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"\nEnter the array elements :\n";
    for (int i=0;i<n;i++){
        cin>>Array[i];
    }
    cout<<"\nThe array elements are as follows :\n";
    for (int i=0;i<n;i++){
        cout<<Array[i]<<" ";
    }
    insert_sort(Array, n);
    cout<<"\nThe sorted array is as :\n";
    for (int i=0;i<n;i++){
        cout<<Array[i]<<" ";
    }
    cout<<"\nEnter the element to be searched for : ";
    cin>>element;
    int min =0;
    int max = n-1;

    for (int i=0;i<n;i++){
        int mid = (min+max)/2;
        if (Array[mid] == element){
            cout<<"\nThe element has been found at index "<<mid;
            break;
        }
        else if(element<Array[mid]){
            max = Array[mid];
        }
        else if(element>Array[mid]){
            min = Array[mid];
        }
        else{
            cout<<"\nThe element is not found !!\n";
        }
    }
}