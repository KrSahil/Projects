#include<iostream>
using namespace std;


void decreasing(int n){
    //base case
    if(n==0){
        return;
    }
    cout<<n<<", ";
    decreasing(n-1); //going towards the base case
    
}

void increasing(int n){
    
    if(n==0){
        return;
    }
    increasing(n-1);
    cout<<n<<", ";
}



  
int main(){
    int n;
    cin>>n;

//    increasing(n)<<endl;
    decreasing(n);
    cout<<endl;
    increasing(n);

 
return 0;
}