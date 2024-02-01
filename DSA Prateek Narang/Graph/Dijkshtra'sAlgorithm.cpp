#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;
  
class Graph{
    int V;
    list<pair <int,int> > *l;
public:
    Graph(int v){
            V= v;
    }

    void addEdge(int u,int v,int wt, bool undir = true){
        l[u].push_back({wt,v});
        if(undir){
            l[v].push_back({wt,u});
        }
    }

    int dijkstra(int src,int dest){
        //two data structure
        //visited ds
        vector<int> dist(V,INT_MAX); //2 purpose - node has been visited or not , if visited what is the distance
        set<pair<int,int>> s;

        //ini
        dist[src] = 0;
        s.insert({0,src}); //set

        while(!s.empty()){
            auto it = s.begin();

            int node = it->second;
            int distTilNow = it->first; //Distance covered till now

            s.erase(it); //pop

            //Iterate over the neighbour of the nodes
            for(auto nbrPair : l[node]){

                int nbr = nbrPair.second; //gives node name
                int currentEdge = nbrPair.first; //length of the edge
                //whole entity is neighbour pair

                if(distTilNow+currentEdge < dist[nbr]){
                    //remove if such a pair already exists

                auto f = s.find({dist[nbr],nbr});
                if(f!=s.end()){
                    s.erase(f);
                }
                //insert the updated value with the new distance

                    dist[nbr]= distTilNow + currentEdge;
                    s.insert({dist[nbr],nbr});
                }
            }
        }
        //single source shortest distance to all other nodes
        for (int i=0;i<V;i++){
            cout<<"Node i "<<i <<" Dist "<<dist[i]<<endl;
        }
        return dist[dest];
    }
};

int main(){
 
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);



    cout<<g.dijkstra(0,4)<<endl;
 
return 0;
}