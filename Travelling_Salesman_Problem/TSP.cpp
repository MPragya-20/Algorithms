#include<bits/stdc++.h>
using namespace std;
#define v 4
#define inf  999

int TSP(int graph[v][v], int src ){
    vector<int> vertices;

    for (int i =0;i<v;i++){
        if (i!=src){
            vertices.push_back(i);
        }
    }
    int minWeight = inf;

    do{
        int currentPathWeight = 0;
        int source = src;

        for(int i = 0;i<v-1;i++){
            currentPathWeight+=graph[source][vertices[i]];
            source = vertices[i];
        }
        currentPathWeight+=graph[source][src];

        minWeight = min(minWeight, currentPathWeight);
    }while(next_permutation(vertices.begin(), vertices.end()));

    return minWeight;
}

int main(){
    int  src;
    int arr[v][v];
    cout<<"\nEnter the cost adjacency matrix:\n";
    for (int i = 0;i<4;i++){
        for (int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"\nEnter the source: ";
    cin>>src;

    cout<<"\nThe min cost for TSP : "<<TSP(arr, src)<<endl;
    return 0;
}