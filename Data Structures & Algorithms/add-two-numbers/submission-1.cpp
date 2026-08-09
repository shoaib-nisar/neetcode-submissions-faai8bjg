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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1->next,*temp2=l2->next;
        int n=(l1?l1->val:0) + (l2?l2->val:0);
        int c=n/10;
        ListNode* head=new ListNode(n%10);
        ListNode* temp=head,*curr=nullptr;
        while(temp1 || temp2)
        {
            n=(temp1?temp1->val:0) + (temp2?temp2->val:0) + c;
            c=n/10;
            curr=new ListNode(n%10);
            temp->next=curr;
            temp=curr;

            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(c){
        curr=new ListNode(c);
        temp->next=curr;
        }
        return head;
    }
};
