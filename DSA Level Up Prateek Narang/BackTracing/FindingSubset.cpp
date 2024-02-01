#include<iostream>
using namespace std;

void findSubSet(char *input,char *output, int i, int j){
        //base case
        //whenever we encounter NULL we print the array
        if(input[i]=='\0'){
            output[j] == '\0'; //inorder to avoid garbage getting printed
            cout<<output<<endl;
            return;
        }
        //rec case
        //Include the ith letter
        output[j]=input[i];
        findSubSet(input,output,i+1,j+1);
        //Exclde the ith letter
        findSubSet(input,output,i+1,j); //previous step gets overwritten
}
  
int main(){
    char input[100];
    char output[100];//single output array shared among all the function calls
    cin>>input;


 
return 0;
}