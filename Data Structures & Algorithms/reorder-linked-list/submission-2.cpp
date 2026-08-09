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
        ListNode* slow=head,*fast=head,*prev=nullptr,*list1=nullptr,*list2=nullptr;
       //Finding the middle
        while(fast && fast->next!=nullptr)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        } 
        if(fast)
        {
            list1=head,list2=slow->next;
            slow->next=nullptr;
        }
        else
        {
            list1=head,list2=slow;
            prev->next=nullptr;
        }
        //reverse list
            if(list2 && list2->next!=nullptr){
            ListNode* curr=list2,*next1=curr->next;
            while(next1)
            {
                prev=curr;
                curr=next1;
                next1=curr->next;

                curr->next=prev;
            }
            list2->next=nullptr;
            list2=curr;
            }

        //Alternatively adding 2 lists
        ListNode* temp1=list1,*temp2=list2,*prev1=list1,*prev2=list2;
        while(temp2 && temp1)
        {
            prev1=temp1;
            prev2=temp2;
            temp1=temp1->next;
            temp2=temp2->next;

            prev2->next=prev1->next;
            prev1->next=prev2;
        }
    }
};
