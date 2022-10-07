#include <bits/stdc++.h> 

using namespace std; 

struct node {
    char currentCharacter;       
    bool isWord;
   //  int priority = 0;            
    struct node *children[27];  // [null,null,null,......,null]
    node() {
        isWord = false;
    }
}*trie; 

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
}

void insertWord(string word) {   
    node *currentNode =  trie;  //1
    for (int i = 0; i< word.length(); i++) { //n
        int character = word[i] - 'a';      //1
        if(currentNode->children[character] == NULL ) {//1
            currentNode->children[character] = new node();//1
        }
        currentNode = currentNode->children[character];//1
        currentNode->currentCharacter = word[i];//1
    }
    currentNode->isWord = true;//1
}

bool searchWord(string word) {   
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {//n
        int character = word[i] - 'a';      //1
        if(currentNode->children[character] == NULL ) {//1
           return false;
        }
        currentNode = currentNode->children[character];//1
    }
    cout<<currentNode->currentCharacter<<endl;//2
    return currentNode->isWord;//2
}

int isWordnode(node* root, char* word) {
    node* temp = root;
    for (int i=0; word[i]; i++) {
        int position = (int) word[i] - 'a';
        if (temp->children[position]) {
            temp = temp->children[position];
        }
    }
    return temp->isWord;
}
node* delete_trie(node* root, char* word) {
    if (!root){//1
        return NULL;
    }
    if (!word || word[0] == '\0'){//1
    return root;
    }
    if (!isWordnode(root, word)) {//n+1
        return root;
    }
    
}

void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}

int main() {

    init();  
    string word = "auto";
    insertWord(word);
    isThereWord(word);
    word = "automovil";   
    insertWord(word);
    isThereWord("auto");
    isThereWord(word);
    return 0;
}