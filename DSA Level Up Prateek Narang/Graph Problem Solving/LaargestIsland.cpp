#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int m,int n){ // i,j current cell
    visited[i][j] = true;
    int cs = 1; // + the size returned by child componenet
    
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1}; 

    for (int k = 0; k<4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(nx>=0 && nx<m && ny>=0 && ny<n && matrix[nx][ny] && !visited[nx][ny]){
            int subcomponent = dfs(matrix,visited,nx,ny,m,n);
            cs += subcomponent;
        }
    }
    return cs; 
}

int largest_island(vector<vector<int>> matrix){
    //return the size of largest island in grid
    int m = matrix.size();
    int n = matrix[0].size();

    //visited matrix
    vector<vector<bool>> visited(m,vector<bool>(n,false));//it is going to have m rows and each rows is intitalized with n columns 
    int largest = 0;

    for (int i = 0; i<m; i++){ //iterate on every location and do dfs
        for (int j = 0; j<n ; j++){
            if(!visited[i][j] && matrix[i][j] == 1){ //as 1 repsresnt island, and we only need the size of island
                //go and caluclate the size of this component
                //we can make a  dfs helper method to compute this particualr size
                int size = dfs(matrix,visited,i,j,m,n);
                if(size>largest){
                    largest = size;
                }
            }
        }
    }
    return largest;    
}
  
int main(){
    vector<vector<int> > grid = {
                            {1,0,0,1,0},
                            {1,0,1,0,0},
                            {0,0,1,0,1},
                            {1,0,1,1,1},
                            {1,0,1,1,0}
                            };

    cout<<largest_island(grid)<<endl;
 
return 0;
}