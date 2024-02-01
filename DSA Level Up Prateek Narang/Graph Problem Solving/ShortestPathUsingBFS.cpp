#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>*l;
public:
    Graph(int v){
        V=v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true){
        l[i].push_back(j);

        if(undir){
            l[j].push_back(i);
        }
    }
    void bfs(int source, int dest = -1){
        queue<int> q;
        //we need to maintiain weather the node has been visited or not
        bool *visited = new bool[V]{0}; //intitalizing it with 0
        //creating a distance array
        int *dist = new int[V]{0};
        //creating a parent array, so that we can trace out the path
        int *parent = new int[V];

        //all memebres of the parent array are going to be inititalized as -1
        for(int i=0; i<V;i++){
            parent[i] = -1;
        }


        q.push(source);
        visited[source] = true;
        //parent of my source node is source itself
        parent[source] = source;
        //distance of source node from itself is going to be zero
        dist[source] = 0;
        //we have to update above two arrays  for all the nodes we are going to visit

        while(!q.empty()){
            //do something work for every node
            int f = q.front();
            cout<<f<<endl;
            q.pop();

            //Push the nbrs of current node if they are not already
            for (auto nbr : l[f]){ //l[f] is the list that gives the nbrs of the current node
                if(!visited[nbr]){
                    q.push(nbr);
                    //updating parent and distance
                    parent[nbr] = f; //parent of the node that we are visiting i.e. nbrs is going to be the parent node
                    //parent of neighbour is going to be f

                    //and distance of neighbour is going to be distance of  it's parent + 1
                    dist[nbr] = dist[f] + 1;


                    visited[nbr]= true; //but we have not printed
                }
            }
        }
        //print the shoretst distance
        for (int i = 0; i<V; i++){
            cout<<"Shoretest distace to "<<i<<" is "<<dist[i]<<endl;
        }

        //print the path from a source to any destination
        if(dest!=-1){
            int temp = dest;
            while(temp !=source){
                //go to it's parent
                cout<<temp<<"-->";
                temp = parent[temp];
            }
            cout<<source<<endl;
        }
    }
};
  
int main(){
     Graph g(7);

     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(3,5);
     g.addEdge(5,6);
     g.addEdge(4,5);
     g.addEdge(0,4);
     g.addEdge(3,4);

    g.bfs(1);
    //find the shortes path from 1 to 6
    g.bfs(1,6);
 
return 0;
}