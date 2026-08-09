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
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head,*temp=nullptr,*curr=head;
        stack<ListNode*> st;
        //Finding the middle
        while(fast && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        temp=slow->next;
        slow->next=nullptr;
        while(temp)
        {
            st.push(temp);
            temp=temp->next;
        }

        while(!st.empty())
        {
            temp=st.top();
            temp->next=curr->next;
            curr->next=temp;
            curr=temp->next;
            st.pop();
        }
    }
};
