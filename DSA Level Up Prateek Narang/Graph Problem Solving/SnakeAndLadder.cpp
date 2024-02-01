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
        l = new list<int>[V+1];
    }

    void addEdge(int i, int j){
        l[i].push_back(j);
    }
     
    int minCostBFS(int source, int dest){
        queue<int> q;
        vector<bool> visited(V,false);
        vector<int> dist(V,0);

        q.push(source);
        visited[source] = true;
        dist[source] = 0;

        while(!q.empty()){  
            int f = q.front();
            q.pop();

            for (auto nbr : l[f]){ 
                if(!visited[nbr]){
                    q.push(nbr);
                    dist[nbr] = dist[f] + 1;                    
                }
            }
        }
        return dist[dest];
    }
};

int min_dice_throws(int n,vector<pair <int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n+1,0); //it tells what jump (+ or -) , I'll get at a praticular index
                            //initally, it is initialzed with zero

    //board to graph conversion
    for(auto sp:snakes){
        int s = sp.first;
        int e = sp.second;
        board[s] = e-s;
    }

    for(auto lp: ladders){
        int s = lp.first;
        int e = lp.second;
        board[s] = e-s;
    }

    //Graph 
    Graph g(n+1); //n+1, because indexin is 1 based
    for(int u = 1; u<n; u++){
        for(int dice =1; dice<=6; dice++){
            int v = u + dice;
            v += board[v]; 
            if(v<=n){
                g.addEdge(u,v);
            }
        }        
    }
    return g.minCostBFS(1,n);

}
  
int main(){
    // Let us construct the board given in above diagram
    int N = 30;
    int moves[N];
    for (int i = 0; i < N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
 
   // cout << "Min Dice throws required is "<< min_dice_throws(moves, N);
    return 0;
  
 
return 0;
}


/*
//2nd way 

// C++ program to find minimum number of dice throws
// required to reach last cell from first cell of a given
// snake and ladder board
#include <iostream>
#include <queue>
using namespace std;

// An entry in queue used in BFS
struct queueEntry {
	int v; // Vertex number
	int dist; // Distance of this vertex from source
};

// This function returns minimum number of dice throws
// required to Reach last cell from 0'th cell in a snake and
// ladder game. move[] is an array of size N where N is no.
// of cells on board If there is no snake or ladder from
// cell i, then move[i] is -1 Otherwise move[i] contains
// cell to which snake or ladder at i takes to.
int getMinDiceThrows(int move[], int N)
{
	// The graph has N vertices. Mark all the vertices as
	// not visited
	bool* visited = new bool[N];
	for (int i = 0; i < N; i++)
		visited[i] = false;

	// Create a queue for BFS
	queue<queueEntry> q;

	// Mark the node 0 as visited and enqueue it.
	visited[0] = true;
	queueEntry s
		= { 0, 0 }; // distance of 0't vertex is also 0
	q.push(s); // Enqueue 0'th vertex

	// Do a BFS starting from vertex at index 0
	queueEntry qe; // A queue entry (qe)
	while (!q.empty()) {
		qe = q.front();
		int v = qe.v; // vertex no. of queue entry

		// If front vertex is the destination vertex,
		// we are done
		if (v == N - 1)
			break;

		// Otherwise dequeue the front vertex and enqueue
		// its adjacent vertices (or cell numbers reachable
		// through a dice throw)
		q.pop();
		for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
			// If this cell is already visited, then ignore
			if (!visited[j]) {
				// Otherwise calculate its distance and mark
				// it as visited
				queueEntry a;
				a.dist = (qe.dist + 1);
				visited[j] = true;

				// Check if there a snake or ladder at 'j'
				// then tail of snake or top of ladder
				// become the adjacent of 'i'
				if (move[j] != -1)
					a.v = move[j];
				else
					a.v = j;
				q.push(a);
			}
		}
	}

	// We reach here when 'qe' has last vertex
	// return the distance of vertex in 'qe'
	return qe.dist;
}

// Driver program to test methods of graph class
int main()
{
	// Let us construct the board given in above diagram
	int N = 30;
	int moves[N];
	for (int i = 0; i < N; i++)
		moves[i] = -1;

	// Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout << "Min Dice throws required is "
		<< getMinDiceThrows(moves, N);
	return 0;
}


*/