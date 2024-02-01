#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int V){
        this-> V =V;
        l = new list<int>[V];
    }
    void addEdge(int x,int y){
        //directed graph
        l[x].push_back(y);
    }

    void topological_sort(){
        vector<int> indegree(V,0); //it has v nodes and initialized with 0
        //Iterate over all the edges to find the right indegree
        for (int i = 0; i<V; i++){

            for (auto neighbour : l[i]){
                indegree[neighbour]++;
            }
        }
        //bfs
        queue<int> q;
        //initialize the q with the nodes having 0 indegree
        for (int i = 0;i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //start poping nodes
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            //iterate over the neighbour if this node reduce their indegree by 1
            for (auto neigbour:l[node]){
                indegree[neigbour]--;
                if(indegree[neigbour]==0){
                    q.push(neigbour);
                }
            }

        }
    }
};
  
int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);

    g.topological_sort();

return 0;
}