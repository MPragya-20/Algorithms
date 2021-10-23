#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public :
    int src;
    int dest;
    int weight;
};
bool compare(Edge a, Edge b){
    return (a.weight < b.weight);
}
int find_parent(int v, int parent[]){
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find_parent(parent[v], parent); //path compression
}
void kruskalAlgo(Edge *input, int E, int V){
    //Sort the input array in ascending order based on weights
    sort(input, input+E, compare);
    Edge * output = new Edge[V-1]; // Array of type Edge -> coz MST has V-1 edges

    int parent[V];
    for (int i=0;i<V;i++){
        parent[i] = i; //Every node is the parent of itself now
    }


    int count = 0; //to take note on how many edges we covered
    int i = 0; //current edge index variable

    while ( count != V-1){
        Edge currentEdge = input[i];//current smallest weighted edge
        //now we can't directly put this edge in MST, so we need
        //Union Find_parent Algo
        //Union by Rank and Path Compression can be used 

        int sourceParent = find_parent(currentEdge.src, parent);
        int destParent = find_parent(currentEdge.dest, parent);

        if (sourceParent != destParent){
            output[count++] = currentEdge;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    int mincost = 0;
    cout<<"\nThe final MST :\n";
    for (int i=0; i<V-1;i++){
        if (output[i].src<output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
        mincost+=output[i].weight;
    }
    cout<<"\n Minimum cost = "<<mincost;
}

int main(){
    int V, E;
    Edge * input = new Edge[E];
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"\nEnter the number of Edges : ";
    cin>>E;
    cout<<endl;
    cout<<"Enter the source  dest    weight(space separated for each edge):\n";
    for (int i = 0; i<E;i++){
        cin>>input[i].src>>input[i].dest>>input[i].weight;
    } //took the input
    kruskalAlgo(input, E, V);
}