#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
  
int main(){

    char input[1000];
    cin.getline(input,1000);

    //strok()

/*    
    cout<<strtok(input," ")<<endl;  //you only get the first function
  //  cout<<strtok(input," ")<<endl;
  //  cout<<strtok(input," ")<<endl;
  //  cout<<strtok(input," ")<<endl; //this will print multiple times just the first string

    //so the solution is , in subsequce call we pass NULL
    cout<<strtok(NULL," ")<<endl;
    cout<<strtok(NULL," ")<<endl;
    cout<<strtok(NULL," ")<<endl;
    cout<<strtok(NULL," ")<<endl;
    cout<<strtok(NULL," ")<<endl; //internally maintains he state of the string you passed in the last function call
 
 */

    char *token = strtok(input," ");
    

    while (token != NULL){
        cout<<token<<endl;
        token = strtok(NULL," ");
    }


return 0;
}