#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> matrix, vector<vector<bool>> &visited,ctor<vector<int>> &cache,int i, int j,int m, int n){ //ccache = DP array
    visited[i][j] = 1;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,1,-1};

    int cnt = 0;
    for (int k = 0; k<4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(nx>=0 && nx<m && ny<n && ny>=0 && matrix[nx][ny]> matrix[i][j]){ //we are going in neighbouring element only if it is greater the it
            int subProblemCnt = 0;
            if(visited[nx][ny]){ //if the neighour is already visited
                //we update our count
                cnt = max(cnt,1+cache[nx][ny]); //cnt = whatever count we had
                                                //if the neighour is already visited
                                                //1 + [dp of neighbour]  
            }
            else{
                dfs(matrix,visited,cache,nx,ny,m,n); //if it is not visited we make a dfs call
                cnt = max(cnt, 1 + cache[nx][ny]);
            }
        }
    }
    cache[i][j] = cnt; // finally after we are dont we store the cache value in it's parent cell
    return; //this we do for all the cells in the matrix
}

int longestPathSequence(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> visited(m+1,vector<bool>(n+1,0));
    vector<vector<int>> cache (m+1, vector<int>(n+1,0));
    //do it dfs from every cell //and store the length of maximum len seq starting from the cell
    int ans = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            dfs(matrix,visited,cache,i,j,m,n);
            ans = max(ans,cache[i][j]);
        }
    }
    return ans+1;
}
  
int main(){
 

 
return 0;
}