#include<iostream>
#include<cstring>
using namespace std;

char *mystork(char *str,char delim){ //first call it will be string other wise it wil be null
    //static variable gets destroyed after function call
    //so return a dynamic array "token"
    static char *input = NULL;
    if(str!=NULL){
        input = str;
    }
    if(input == NULL){
        return NULL;
    }

    char *token = new char[strlen(input)+1];
    int i  =0;

    for(; input[i]!='\0';i++){
        if(input[i]!=delim){
            token[i] = input[i];
        }
        else{
            token[i]= '\0';
            input = input + i + 1; //we updated our static variale
            return token;

        }
    }
    //oout of the loop 
    token[i]=='\0';
    //reset the input as NULL
    input = NULL;
    return token;

}
  
int main(){
    char s[100];
    cin.getline(s,100);

    char *token = mystork(s,' ');

    while(token!=NULL){
        cout<<token<<endl;
        token = mystork(NULL,' ');
    }

return 0;
}