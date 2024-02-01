#include<iostream>
using namespace std;

void housing (int *arr, int n, int k){
    int i = 0;
    int j = 0;
    int cs = 0;

    while (j<n){
        //ecpand to right
         cs += arr[j];
         j++;
         //reove elemetns from the left till cs>sum and i<j
         while(cs>k && i<j){
            cs = cs - arr[i];
            i++;
         }
         //check if any given point
         if(cs == k){
            //print the window
            cout<<i<<"-"<<j-1<<endl ; //we have done j++ so we subtract 1 
                        //when you are including j in current window it inculeds the sum part and a extra j
         }
    }

    return;
}
  
int main(){
    int plots[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plots)/sizeof(int);
    int k = 8;

    housing (plots,n,k);
 
return 0;
}