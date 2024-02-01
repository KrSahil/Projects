#include<iostream>
#include<string>
using namespace std;
  
int main(){
    string paragraph = "We are learning about STL strng. STL string class is quit powerful";

    string word;
    getline(cin,word);

    //find function -> search particular ward in a paragraph
   // cout<<paragraph.find(word)<<endl; //--> this will give very long unsined integer, if element not fund
   size_t index = paragraph.find(word);

   if(index!=-1){
        cout<<"first occurance -> "<<index<<endl;        
   }
   index = paragraph.find(word,index+1);
   if(index != -1){
        cout<<"second occureance -> "<<index<<endl;
   }

   if(index == -1){  //converting unsigned to signed integer
        cout<<"Stringn not found";
   }

 
return 0;
}