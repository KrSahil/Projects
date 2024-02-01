#include<iostream>
#include<cstring>
using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};  

void printKeypadOutput(string input,string output,int i=0){ // i denotes at what positin we are at given input
    if(input[i]=='\0'){ // we are finished with the input string
        cout<<output<<endl;
        return;
    }

    //rec casee
    //extract the current digit
    int current_digit = input[i] - '0';
    if (current_digit == 0 || current_digit == 1){
        //just go to the next index and make a recursive call
        printKeypadOutput(input,output,i+1);
    }

    //keypad
    for (int k = 0;k<keypad[current_digit].size();k++){
        printKeypadOutput(input,output+keypad[current_digit][k], i+1);
    }
    return;

}


int main(){
    string input;
    cin>>input;

    string output;
    printKeypadOutput(input,output);
 

 
return 0;
}