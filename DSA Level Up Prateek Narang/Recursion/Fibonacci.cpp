#include<iostream>
using namespace std;

int NthFibonacci(int n){
    if (n==0 || n== 1){
        return n;
    }
    int f1 = NthFibonacci(n-1);
    int f2 = NthFibona cci(n-2);
    return f1+f2;
}
  
int main(){
    cout<<NthFibonacci(3); 

 
return 0;
}