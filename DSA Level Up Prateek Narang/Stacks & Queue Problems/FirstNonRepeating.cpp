#include<iostream>
#include<queue>
using namespace std;
  
int main(){
    //first non repeating character in the running stream
    queue<char> q;
    int freq[27] = {0}; //a-z
    char ch;
    cin>>ch;

    while(ch!='.'){
        //letter
        q.push(ch);
        freq[ch-'a']++; //ch-'a' gives us the right index 

        //query  -> remove all chars from front of queue till you get a chr with freq 1
        while(!q.empty()){
            int idx = q.front() - 'a';
            if(freq[idx]>1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }
 

 
return 0;
}

/*

a -> 97
b -> 98
c -> 99
.
.
z -> 122
a b c d e f g h i j k l m n o p q r s t u v w x y z
0 1 2 3 4 5 6 7 8 9 10...........................25

'b' - 'a' = 98 - 97 = 1;
'c' - 'a' = 99 - 97 = 2
char t = 97;
t = a;


*/