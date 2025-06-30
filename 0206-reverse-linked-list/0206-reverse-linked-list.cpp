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

void recursive(ListNode*&head,ListNode* prev, ListNode*curr)
   {
       if(curr==NULL)
       {
           head=prev;
           return ;
       }

    //    prev=curr;
    //    curr=curr->next; // RECURSION PLAY WITH POINTERS IN THE FUNCTION CALLING (BECAUSE WE HAVE TO CHANGE POINTERS AT EVERY RECURSIVE CALL)
       recursive(head,curr,curr->next);
       curr->next=prev;
       return ;

   }
    ListNode* reverseList(ListNode* head)
    {
        // if(head==NULL){
        //     return NULL;
        // }
        // ListNode*curr=head;
        // ListNode*prev=NULL;
        // while(curr!=NULL)
        // {

        //     ListNode*temp=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=temp;            
        // }
        // return prev;

        // RECURSIVE APPROACH
          ListNode*curr=head;
        ListNode*prev=NULL;
        recursive(head,prev,curr);
        return head;

    }
};