#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define M 3
#define N 4

class Node{
    public:
        char s;
        unordered_map<char,Node*> children;
        string word;
        bool isTerminal;

        Node(char s){
            this->s = s;
            isTerminal = false;
            word = ""; //update this word only at the leaf node
        }
};

class Trie{
    public:
        Node*root;

        Trie(){
            root  = new Node('\0');
        }

        void addWord(string word){

            Node*temp = root;
            for(auto ch:word){
                if(temp->children.count(ch)==0){ //if it doesn't contains
                    temp->children[ch] = new Node(ch);
                }
                temp = temp->children[ch];
            }
            //last node
            temp->isTerminal = true;
            temp->word = word;
        }

};

//main algorithm (8 way dfs + trie guided search)

void dfs(char board[M][N],Node *node, int i, int j, bool visited[][N],unordered_set<string> &output){

    //base case
    char ch = board[i][j]; //the cell at which u are standing
    if(node->children.count(ch)==0){ //if the node of trie at which u are currently at doesn't contains this particular child, then u  cna simply return
        return;
    }

    //otherwise, trie contains this node
    //we are going to visit a node , so first lets mark it as visited
    visited[i][j] = true;
    //let's go to this node
    node = node->children[ch];
    //recursively check to which cells u can go from the present cell

    //it it is terminal node in the trie, we dont stop we explore it furher until the branch is completely visited
    if(node->isTerminal){
        output.insert(node->word); //the entire word is stored inside the treminal node 
        //return
        //we dont return because we want to explore further
        //the the preset letter can prefix of many words
    }
    //explore the neighbours
    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};

    //we can initiate 8 calls
    for(int k=0;k<8;k++){
        int ni = i +dx[k]; //ni = new i
        int nj = j +dy[k];

        //if it is in bounds and is not visited in current path
        if(ni>=0 && nj>=0 && ni<M && nj < N && !visited[ni][nj]){ //check, we don't go to negative index and we dont out of the boundry as well
            dfs(board,node,ni,nj,visited,output); //this will initiate a 8 way recursion     
        
        }
    } 
    //last step(backtracking)
    //when we go back from the current letter (after visiting all it's children) we mark it as not visited
     visited[i][j] = false;
     return;

}
  
int main(){

    string words[]  = {"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};

    char board[M][N] = {{'S','E','R','T'},
                         {'U','N','K','S'},
                         {'T','C','A','T'} };
 
    //1.trie
    Trie t;
    for(auto w:words){
        t.addWord(w);
    }

    //2. Take a container to store words that are found in dfs search
    //we are using unorderd set because there can be multiple ways to form the same node
    /*
        O Y O
          Y 
            O   

        so inorder to avoid dublicates we use unordered set
    */
   unordered_set<string>output;

   //3rd step = 8 way DFS search from every cell
   bool visited[M][N] = {0}; //initalized with all 0's

   for(int i = 0; i<M; i++){
    for(int j = 0; j<N; j++){
        dfs(board,t.root,i,j,visited,output);  //do the dfs on the board
        //we give root node of the trie to guide the search and give at what location u r currently on the board
        /*
        we pass (i,j) as they are current position
        we make visted array so that we dont end of constriuction the smae string again and again from the same node
        */

       //reset the visited array after every call  (while becktracking)


    }
   }

   //4th step : print the output
   for (auto word: output){ //iterate over the undordered set
        cout<<word<<endl;
   }


 
return 0;
}