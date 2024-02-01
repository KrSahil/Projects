#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
    }

    

    bool dfs(int node, vector<bool> &visited, vector<bool> &stack){ //we are passing this vector by refrence because,  same changes are precesting across the call
        //return true if backedge is found,  else false 
        visited[node] = true;
        stack[node] = true;

            //do some work at node
        for(int nbr: l[node]){
            if(stack[nbr] == true){
                return true; //we found back edge
            } //this is the case when, it immeditately leads to the backedge


            else if(visited[nbr] == false){
                bool nbrFoundACycle = dfs(nbr,visited,stack);
                if(nbrFoundACycle){
                    return true;
                }
            } //this is the case, when it's neighbour recursively leads to the backedge
        }

            //going back
        stack[node] = false;
        return false;

    }

    bool contains_cycle(){
        vector<bool> visited(V,false);
        vector<bool> stack(V,false);

        for(int i = 0; i<V; i++){
            if(!visited[i]){
                if(dfs(i,visited,stack)){
                    return true;
                } 
            }
    }
        return false;
    }

    
};
  
int main(){

    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    cout<<g.contains_cycle();

return 0;
}