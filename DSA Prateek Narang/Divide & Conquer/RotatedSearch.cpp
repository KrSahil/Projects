#include<iostream>
#include<vector>
using namespace std;

int rotated_search(vector<int> a, int key){
    int n = a.size();

    //logic
    int s = 0;
    int e = n-1;

    while (s<=e){
        int mid = (s+e)/2;

        if (a[mid]==key){
            return mid;
        }

        //2 cases - mid lies in left or right

        if (a[s]<= a[mid]){
             //left:  left part is sorted
            if(key>=a[s] && key <= a[mid]){
                e = mid-1;
            }
            else{  //left : right part is sorted
                s = mid + 1;
            }
        }
        else{
            //right 
            //right : left part sorted
            if (key>=a[mid] && key<=a[e]){
                s = mid+1;
            }
            else{  //right : right part sorted
                e = mid-1;
            }
        }


    }
    //element not found
    return -1;


}
  
int main(){

   
   vector<int> a{4,5,6,7,0,1,2,3};
    int key;
    cin>>key;
    cout<<rotated_search(a,key);
 
return 0;
}