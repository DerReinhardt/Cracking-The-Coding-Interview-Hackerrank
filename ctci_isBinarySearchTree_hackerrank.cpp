/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool explore(Node * root, int & lastSeen){  // traverse inorder just keeping track of the last element seen
    if(!root) return true;
    
    if(!(explore(root -> left, lastSeen))) return false;
    
    if(lastSeen >= root -> data) return false;
    
    lastSeen = root -> data;
    
    if(!(explore(root -> right, lastSeen))) return false;
    
    return true;
}

   bool checkBST(Node* root) {
      if(!root) return true;
      int lastSeen = -1;
      return explore(root, lastSeen);
   }
