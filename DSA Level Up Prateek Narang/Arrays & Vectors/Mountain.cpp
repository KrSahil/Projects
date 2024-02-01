#include<iostream>
#include<vector>
using namespace std;

int highest_mountain(vector<int> a){
    int n = a.size();
    int largest = 0;

    for(int i = 1;i<n-2;){//becaues 0th element cannot be a peak
        //check if a[i] is peak or not
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            //do some work
            int count = 1;
            int j = i;
            //cout forward (left)
            while(j>=1 && a[j]>a[j-1]){ //we are taking j>=1 because,if j becomes 0 , a[j-1] will give segmentation fault
                j--;
                count++;
            }
            //count backward (right)
            while(i<=n-2 && a[i]>a[i+1]){  //we are taking i<=n-2 because, if i becomes n-1, a[i+1] will give segmentation fault
                i++;
                count++;
            }
            //if count becme greater than largest
            largest = max(largest,count);
        }
        else{
            i++;
        }
        
    
    }
    return largest;

}
  
int main(){
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<highest_mountain(arr);

 
return 0;
}