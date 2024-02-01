#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findSubsets( char *input, char *output, int i , int j, vector<string> &list){
    //base case
    if (input[i]=='\0'){
        output[j]='\0'; // in order to avoid garabage gettinig printed

        string temp(output);
        list.push_back(temp);

        return;
    }

    //rec case
    //Include the Ith letter
    output[j] = input[i];
    findSubsets(input,output,i+1,j+1,list);

    //Exclude the Ith letter
    //overwriting
  
    findSubsets(input,output,i+1,j,list);


}
  
int main(){

    char input[100];
    //single output array that will be shared across all the function calls
    char output[100];

    vector<string> list;



    cin>>input;

    sort(list.begin(),list.end());

    findSubsets(input,output,0,0,list);

    for (auto s:list){
        cout<<s<<" ";
    }

return 0;
}