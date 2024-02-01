#include<iostream>
using namespace std;


//problem: print all pairs of elements
void printAllPairs(int arr[],int n){

    //2 nested loops
    for (int i =0; i<n;i++){
        
        int x = arr[i];

        /*
        //I did not understand why i+1;
        for (int j = i+1;j<n; j++){
            int y = arr[j];

            cout<< x <<","<< y << endl;
            */

        for (int j = 0;j<n; j++){
            // if we put j = 0 it will print all possibel pairs including already selected pairs
            int y = arr[j];

            cout<< x <<","<< y << endl;
        }
        cout<<endl;
        
        }
    }



  
int main(){

    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(int);
    
    //Differnt way of printing all the elements in the array
    //pritn all the elements of the array
    for (int x : arr){
        cout<< x <<endl;
    }

    cout<<"All pairs"<<endl;

    printAllPairs(arr,n);

 
return 0;
}