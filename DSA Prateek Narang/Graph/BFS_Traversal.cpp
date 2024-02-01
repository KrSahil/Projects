#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V=v;
        l = new list<int>[v];
    }
    void addEdge(int i, int j , bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void bfs(int source){
        queue<int> q;
        //we have to maintiain weather the node has been visited or not
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source]=true;

        while(!q.empty()){
            //Do some work for every node
            int f = q.front();
            cout<<f<<endl;
            q.pop();

            //push the neighbour of current inside q if they are not already visited
            for(auto nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    //dont want to visiti nod again and again
                    visited[nbr] = true; //but not printed yet
                }
            }
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
 

 
return 0;
}