#include<iostream>
using namespace std;

#define inf 2000

struct Edge{
    int src;
    int dest;
    int weight;
};

struct Graph{
    int V;//This is total no. of vertices in my graph
    int E;//This is total no. of edges in my graph

    Edge *edge;  //The edge property included  
};

Graph* createGraph(int V, int E){
    Graph *newgraph = new Graph;
    newgraph-> V = V;
    newgraph->E = E;
    newgraph->edge = new Edge[E]; //A graph is made of array of edges and each edge has 3 properties

    return newgraph;
}

void BellmanFordAlgo(Graph* mygraph, int src){
    int V = mygraph->V;
    int E = mygraph->E;

    int distanceArray[V];//an array holding the distances

    for (int i = 0;i<V;i++){
        distanceArray[i] = inf;
    }
    distanceArray[src] = 0;

    //Now we need to relax all the edges V-1 times.
    for (int i = 0 ;i<V-1;i++){
        for (int j = 0; j<E;j++){
            int u = mygraph->edge[j].src;
            int v = mygraph->edge[j].dest;

            int weight = mygraph->edge[j].weight;

            if(distanceArray[u]!=inf && distanceArray[v]>distanceArray[u]+weight){
                distanceArray[v] = distanceArray[u]+weight;
            }

        }
    }

    //The following step checks for negative weight cycle
    //One extra loop of relaxing all the edges, if we get even shorter path,
    //Then there is a negative cycle , then Stop
    for (int j = 0; j<E;j++){
        int u = mygraph->edge[j].src;
        int v = mygraph->edge[j].dest;

        int weight = mygraph->edge[j].weight;

        if(distanceArray[u]!=inf && distanceArray[v]>distanceArray[u]+weight){
            cout<<"\nNegative weight Cycle Detected !!\n";
            return;
        }

    }

    for (int i =0;i<E;i++){
        cout<<src<<"    --      "<<i<<"  ->  "<<distanceArray[i]<<endl;
    }

}

int main(){
    int V=3, E=3;
    int src;

    Graph* mygraph =  createGraph(V, E);
    //First Edge
    mygraph->edge[0].src = 0;
    mygraph->edge[0].dest = 1;
    mygraph->edge[0].weight = 10;
 
    // Second Edge
    mygraph->edge[1].src = 0;
    mygraph->edge[1].dest = 2;
    mygraph->edge[1].weight = 5;

    //Third Edge
    mygraph->edge[2].src = 1;
    mygraph->edge[2].dest = 2;
    mygraph->edge[2].weight = -8;

//below example will show -ve edge cycle
    // //First Edge
    // mygraph->edge[0].src = 0;
    // mygraph->edge[0].dest = 1;
    // mygraph->edge[0].weight = 10;
 
    // // Second Edge
    // mygraph->edge[1].src = 1;
    // mygraph->edge[1].dest = 2;
    // mygraph->edge[1].weight = 20;

    // //Third Edge
    // mygraph->edge[2].src = 2;
    // mygraph->edge[2].dest = 1;
    // mygraph->edge[2].weight = -30;

    cout<<"\nEnter the source : ";
    cin>>src;

    BellmanFordAlgo(mygraph, src);

    
    return 0;
}