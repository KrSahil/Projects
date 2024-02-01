#include<iostream>
#include<vector>
using namespace std;

void findSubsets( char *input, char *output, int i , int j){
    //base case
    if (input[i]=='\0'){
        output[j]='\0'; // in order to avoid garabage gettinig printed

        //to make NULL visible 
        if (output[0]=='\0'){
            cout<<"NULL";
        }
        cout<<output<<endl;
        return;
    }

    //rec case
    //Include the Ith letter
    output[j] = input[i];
    findSubsets(input,output,i+1,j+1);

    //Exclude the Ith letter
    //overwriting
  
    findSubsets(input,output,i+1,j);


}
  
int main(){

    char input[100];
    //single output array that will be shared across all the function calls
    char output[100];


    cin>>input;
    findSubsets(input,output,0,0);




 

 
return 0;
}