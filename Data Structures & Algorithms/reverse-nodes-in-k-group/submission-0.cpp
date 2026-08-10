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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        int len=0;
        ListNode* temp=head,*prev=temp,*h=new ListNode(-1),*curr=h;

        while(temp)
        {
            if(len==k){
            prev=temp;
            while(len)
            {
                curr->next=st.top();
                curr=curr->next;
                st.pop();
                len--;
            }
            }
            st.push(temp);
            len++;
            temp=temp->next;
        }

        if(!st.empty() && len==k)
        {
            while(len)
            {
                curr->next=st.top();
                curr=curr->next;
                st.pop();
                len--;
            }
            curr->next=nullptr;
        }else if(len!=k) curr->next=prev;
           
        return h->next;
    }
};
