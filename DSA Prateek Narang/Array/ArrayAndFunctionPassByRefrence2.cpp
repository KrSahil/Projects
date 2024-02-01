#include<iostream>
using namespace std;


/*  
void printArray(int *arr){
    cout<<"In function "<<sizeof(arr) <<endl;
    //only address of array

     int n = sizeof(arr)/sizeof(int);
     for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<endl;
    }
    //here, we dont know the correct value of n as array is not here
}
*/


//here, line 10 is not going to work,
//so instead we imoort value of n from int main()

void printArray(int * arr,int n){
    cout<<"In function "<<sizeof(arr) <<endl;
    arr[0]=100;
    //here values are changed both for main and function as thry share common memory as it is passed by refrence


     //int n = sizeof(arr)/sizeof(int);
     for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<endl;
    }
    //here, we dont know the correct value of n as array is not here
}


int main(){
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"In main "<<sizeof(arr)<<endl;
    //here we get output -> 24 because we have array here
   
   // printArray(arr);
   printArray(arr,n);


    for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<endl;
    }
    
 
return 0;
}