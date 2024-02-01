  #include<iostream>
  using namespace std;

  pair<int,int> staircaseSearch(int matrix[][4],int n, int m , int key){ //matrix==arr
    // pair <int, int> g1;

    //later if the element is not present return {-1,-1}
    if (key < matrix[0][0] or key>matrix[n-1][m-1]){
      return {-1,-1};
    }
    //StairCase search
    int i=0;
    int j = m-1;  // this means we are starting from 40

    while (i<n and j>=0){
      
      if (matrix[i][j]==key){
        return {i,j};
      }
      else if (matrix[i][j]>key){
        j--;
      }
      else{
        i++;
      }
    }
    return {-1,-1}; // if element not found

  }
    
  int main(){
   
  //2D row and column Wise sorted Array
      int arr[][4] = {
                        {10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,48},
                        {32,33,39,50}
                      };
    int n=4, m=4;

    pair<int,int> coords = staircaseSearch(arr,n,m,33);
    cout<<coords.first<<" "<<coords.second;

  return 0;
  }