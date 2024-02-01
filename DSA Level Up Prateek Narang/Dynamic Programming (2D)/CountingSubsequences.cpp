#include<iostream>
using namespace std;

//Top Down
int countSub(string a,string b,int m,int n){

    //base case
    //if all the letter have been mathced or all the letters have been finished
    //Or 2nd case all the string of B has mathced with A
    if((m==-1 && n==-1) || n==-1){
        return 1;
    }
    if(m==-1){
        //the first string is finished but something is still left in string B
        return 0;
    }

    //rec case
    if(a[m] == b[n]){ //if last character match
        //we have 2 options
        //either to take last letter from a or not
        return countSub(a,b,m-1,n-1) + countSub(a,b,m-1,n); 
    }
    return countSub(a,b,m-1,n);

}
  
int main(){
    string a = "ABCECDG";
    string b = "ABC";

    cout<< countSub(a,b,a.size()-1,b.size()-1)<<endl;
 
return 0;
}