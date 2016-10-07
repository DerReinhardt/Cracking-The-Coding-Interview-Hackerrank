/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    if(!head || !(head -> next)) return false;
    
    Node * p = head, * q = head;
    
    while(q && q -> next){
        q = q -> next;                        
        q = q -> next;
        p = p -> next;
        if(p == q) return true;
    }
    
    return false;
}
