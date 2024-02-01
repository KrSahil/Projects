#include<iostream> 
using namespace std;
  
int main(){
    //if we want to avoid garbage values we can initialize it with 0
    
    //int marks[100];
    int marks[100]={0};


    int n;
    cout<<"Enter the no of students";
    cin>>n;

    //assign a value
    marks[0]=1;

    //input
    for (int  i = 1; i < n; i++)
    {
        cin>>marks[i];

        /*we can also update input values
        example
        marks[i]=marks[i]*2;
        */
    }

    //output
    for (int i =0; i<n; i++){
        cout<<marks[i]<<" ,";
    }
    cout<<endl;


    
      
 
return 0;
}