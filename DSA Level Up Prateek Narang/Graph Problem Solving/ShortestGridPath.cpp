#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;

class Node{
public:
    int x;
    int y;
    int dist;

    Node(int x,int y,int dist){
        this->x = x;
        this->y = y;
        this->dist = dist;

    }
};

//compare should return boolean value
//indicating weather the element passed as first argument is considered to go before the second in the specific strict weak ordering
class Compare{
public:
    bool operator()(const Node &a, const Node &b){ //first argument we have passed should go before the second
                                                    //it the first have ditance less than or equal to the distance of some other node than that should come first in the set
        return a.dist <= b.dist;
    }
};

int shortest_path(vector<vector<int>> grid){
    //return the shortes path len

    int m = grid.size(); //finding the number of rows
    int n = grid[0].size(); //finding the number of columns

    int i = 0; //starting cell is 0,0
    int j = 0;

    //2d vector to denote the distance of each cell
    vector<vector<int> > dist(m+1, vector<int>(n+1,INT_MAX)); //distance data structure that will store the distances for all the cell 
    //it has m+1 rows and each row is initalized with n+1 columns //by default value INT_MAX

    dist[i][j] = grid[0][0];
    //initalize set data structure; set will store i,j,dist and it will do sorting based upon the distance    
    set<Node,Compare> s;

    //at any point we have 4 direction to move
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    //insert the first node inside of the set
    s.insert(Node(0,0,dist[0][0]));

    while(!s.empty()){
        //Extract the node which is at the begining of the node
        auto it = s.begin(); //it = iterator
        int cx = it->x; //cx = current x
        int cy = it->y;
        int cd = it->dist;
        s.erase(it); //we are going to remove it because it has been finialized

        //now we can iterate over the neighbour
        //every neighbour can be in 4 directions
        for(int k=0; k<4; k++){
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if(nx>=0 and nx<m and ny>=0 and ny<n and cd + grid[nx][ny] < dist[nx][ny]) { //the cell whic we are going i.e. current edge
                                                                                        //new distance is smaller the old distance
                //remove the old node if it exists
                //so, let's create a tempooraya node by using  the value of that node
                Node temp(nx,ny,dist[nx][ny]);
                if(s.find(temp)!=s.end()){
                    s.erase(s.find(temp));
                }

                //insert the new node in the set
                int nd = grid[nx][ny] + cd;
                dist[nx][ny] = nd;
                s.insert(Node(nx,ny,nd));

            }
        }
    }
    return dist[m-1][n-1];

}
  
int main(){
 

 
return 0;
}