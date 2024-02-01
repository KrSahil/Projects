#include<iostream>
using namespace std;
  
int main(){
 
    int n;
    cin>>n;

    //Dynamic array
    int *arr = new int[n];

    for (int i=0; i<n; i++){
        arr[i]=i;
        cout<<arr[i]<<" ";
    }

    //Delete this array

    delete [] arr;

    //we are still going to get the address if the arr
    //static address doesnt gets deleted until the function call is over
    

    
    cout<<arr<<endl;

    //but the value might get changed
    //the value is not predictable
       cout<<arr[2];
 
return 0;
}