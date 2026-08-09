/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp=head,*prev=nullptr,*curr=nullptr;
       int c=0;

       while(temp){
        c++;
        temp=temp->next;
       }

       int node=c-n+1;
        if(node==1)
        {
            temp=head;
            head=head->next;
            delete temp;
            temp=nullptr;
        }else{
            temp=head;
       while(node!=1)
       {
            node--;
            prev=temp;
            temp=temp->next;
       }
       prev->next=temp->next;
       delete temp;
       temp=nullptr;
        }
        return head;
    }
};
