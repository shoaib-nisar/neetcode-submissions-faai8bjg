/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*,Node*>mpp;
       if(!head) return nullptr;
       Node* h=new Node(head->val);
       mpp[head]=h;
        Node* temp=head->next;
        Node* temp2=h;
       while(temp)
       {
            Node* curr=new Node(temp->val);
            mpp[temp]=curr;
            temp2->next=curr;
            temp2=curr;
            temp=temp->next;
       }
        temp=head;
        temp2=h;
       while(temp)
       {
        if(temp->random) temp2->random=mpp[temp->random];
        temp2=temp2->next;
        temp=temp->next;
       }
       return h;
    }
};
