#include<iostream>
using namespace std;
#define v 5
#define inf 999

int minDist(int dist[], bool visited[]){
    int min = inf;
    int index;

    for (int i =0; i<v;i++){
        if(visited[i] == false && dist[i]<=min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int cost[v][v], int source){
    int dist[v];
    bool visited[v];

    for (int i =0;i<v;i++){
        visited[i] = false;
        dist[i] = inf;
    }
    dist[source] = 0;

    for(int i = 0;i<v;i++){
        int u = minDist(dist, visited);
        visited[u] = true;

        for(int j=0;j<v;j++){
            if (visited[j] == false && cost[u][j]!=0 && dist[u]+cost[u][j]< dist[j]){
                dist[j] = dist[u]+cost[u][j];
            }
        }
    }
    cout<<"\nSource     Destination     Cost\n";
    for(int i=1;i<v;i++){
            cout<<"\n   "<<source<<"     -     "<<i<<"      ->      "<<dist[i]<<endl;
        }
}

int main(){
    int cost[v][v],src;
    cout<<"\nEnter the cost adjacency matrix: \n";
    for (int i =0;i<v;i++){
        for (int j =0;j<v;j++){
            cin>>cost[i][j];
        }
    }
    cout<<"\nEnter the source : ";
    cin>>src;

    dijkstra(cost, src);
    return 0;
}