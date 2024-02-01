#include<iostream>
using namespace std;

int power(int a , int n){
    //base case
    if (n==0){
        return 1;
    }
    return a * power(a,n-1);
}

int powerOptimised(int a , int n){
    //base case
    if (n==0){
        return 1;
    }

    int subProb = powerOptimised(a,n/2);
    int subProbSq = subProb*subProb;
    if (n&1){
        return a*subProbSq;

    }
    return subProbSq;
}
  
int main(){
 int a,b ;
 cin>>a>>b;

cout<<power(a,b)<<endl;
cout<<powerOptimised(a,b);
 
return 0;
}   