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
    ListNode* reverseList(ListNode* head) {
     // Reversing  a LL using a stack
     stack<ListNode*> st;
    ListNode *curr=head;
    if(!head) return head;
     while(curr)
     {
        st.push(curr);
        curr=curr->next;
     }   
        curr=st.top();
        head=curr; st.pop();
     while(!st.empty())
     {
        curr->next=st.top();
        curr=curr->next;
        st.pop();
     }
        curr->next=nullptr;
        return head;
    }
};
