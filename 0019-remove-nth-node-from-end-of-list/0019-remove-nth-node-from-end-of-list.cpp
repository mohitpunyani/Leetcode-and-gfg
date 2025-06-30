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
    int length_of_ll(ListNode*head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *prev=NULL;
        ListNode*curr=head;
        int ll=length_of_ll(head);
        int deleted_node_index=ll-n+1; // DELETED NODE Index from start
        if(deleted_node_index==1)
        {
            head=curr->next;
            return head;
        }
        int count=1;
        while(true)
        {

            if(count==deleted_node_index)
            {

               
                prev->next=curr->next;
                break;
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};