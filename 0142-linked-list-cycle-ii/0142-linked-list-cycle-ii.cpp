/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //  ListNode*slow=head;
        // ListNode*fast=head;
        
        // if(fast==NULL or fast->next==NULL)
        // {
        //     return NULL;
        // }
        // while(fast!=NULL && fast->next!=NULL)
        // {
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast)
        //     {
        //         break;
        //     }
        // }
        // if(fast==NULL or fast->next==NULL)
        // {
        //     return NULL;
        // }
        // slow=head;
        // while(slow!=fast){
        //     slow=slow->next;
        //     fast=fast->next;
        // }
        // return slow;


        // APPROACH MADE USING DRY RUN
         ListNode*slow=head;
        ListNode*fast=head;
        
        if(fast==NULL or fast->next==NULL)
        {
            return NULL;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            if(slow==fast && fast->next!=NULL)
            {
                break;
            }
        }
        if(fast==NULL or fast->next==NULL)
        {
            return NULL;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};