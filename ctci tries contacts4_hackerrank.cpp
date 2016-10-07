#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
When adding a word increase the counter of each of the nodes. Corner case: repeated words will be counted many times instead of just once.
Each node now will cointain the number of possible words because you visited it count times in the construction.
Adding this counter will help to just query up until the end of the queried words instead of visiting each branch of the ending node of the word.

*/


struct Node
{
	int count = 0;
	unordered_map<char, Node *> children;
};

Node * createNode(){	
	return new Node();
}

void addContact(const string & name, Node * root){
	if(!root) return;
	Node * node = root;
	for(char c : name){
		auto it = node -> children.find(c);
		if(it == node -> children.end()){
			Node * aux = createNode();			
			node -> children[c] = aux;
		}		
		node = node -> children[c];
		(node -> count)++;
	}
	
}

int findPartial(const string & name, Node * root){		
	Node * node = root;
	for(char c : name){
		if(node -> children.find(c) == node -> children.end()){
			return 0;
		}
		node = node -> children[c];
	}
	return node -> count;
}


int main(){
    int n;
    cin >> n;
    Node * root = createNode();

    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add"){
        	addContact(contact, root);
        }
        else{
        	cout << findPartial(contact, root) << endl;
        }
    }

    //cout << (root -> children.size()) << endl;

    return 0;
}
