#include<iostream>
#include<cstring>
using namespace std;

void replace_space(char *str){ //character arrays are passed by refrence so we dont need to return the output
    //1 calculate spaces and additional spaces needed
    int spaces = 0;
    for(int i = 0; str[i] !='\0';i++){
        if(str[i]==' '){
            spaces += 1;
        }
    }
    //finding final index
    int idx = strlen(str) + 2*spaces;
    str[idx] = '\0'; //terminating the end with null
    //i points the last character of the input string
    for(int i = strlen(str)-1; i>=0; i-- ){
        if(str[i]==' '){
            str[idx-1]='0';
            str[idx-2]='2';
            str[idx-3]='%';
            idx = idx-3;
        }
        else{
            str[idx-1] = str[i];
            idx--;
        }
    }

}
  
int main(){
    char input[1000];
    cin.getline(input,1000);
    replace_space(input);
    cout<<input<<endl;
 
return 0;
}