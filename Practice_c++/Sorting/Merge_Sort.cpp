#include<iostream>
using namespace std;
void merge(int A[], int p,int q, int r){
    
    int n1 = q-p+1;
    int n2 = r-q;
    int Left[n1];
    int Right[n2];
    for (int i = 0;i<n1;i++){
        Left[i] = A[p+i];
    }
    for (int j = 0;j<n2;j++){
        Right[j] = A[q+j+1];
    }
    int i, j;
    i=j=0;
    int k=p;
    while (i<n1 && j<n2){
        if (Left[i]<=Right[j]){
            A[k] = Left[i];
            i++;
        }
        else {
            A[k] = Right[j];
            j++;
        }
        k++;
    }
    while(i<n1) {       //extra element in left array
        A[k] = Left[i];
        i++; k++;
    }
    while(j<n2) {     //extra element in right array
        A[k] = Right[j];
        j++; k++;
    }
    
}
void merge_sort(int A[], int p, int r){
    int q;
    if (p<r){
        q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main(){
    int n;
    int Array[15];
    cout<<"\nEnter the number of elements :\n";
    cin>>n;
    cout<<"\nEnter the array elements:\n";
    for (int i=0;i<n;i++){
        cin>>Array[i];
    }
    merge_sort(Array, 0, n-1);
    for (int k=0; k<n; k++){
        cout<<Array[k]<<" ";
    }
}