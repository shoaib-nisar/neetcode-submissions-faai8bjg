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
        deque<ListNode*> dq;
        ListNode* curr=head,*left=nullptr,*right=nullptr;
        ListNode* d=new ListNode();
        int i=0;

        while(curr)
        {
            dq.push_back(curr);
            curr=curr->next;
        }
        curr=d;
        while(!dq.empty())
        {
            if(i%2==0)
            {
                left=dq.front();
                curr->next=left;
                dq.pop_front();
            }
            else {
            right=dq.back();
            curr->next=right;
            dq.pop_back();
            }
            curr=curr->next;
            i++;
        }
        curr->next=nullptr;
        head = d->next;
    }
};
