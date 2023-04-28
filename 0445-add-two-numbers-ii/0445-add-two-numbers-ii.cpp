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

class Solution
{
    public:
        ListNode* rev(ListNode *head)
        {
            ListNode *prev = NULL;
            ListNode *curr = head;
            while (curr != NULL)
            {

                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            return prev;
        }
  
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
       	// first reverse both the linked list


        ListNode *head1 = rev(l1);
        ListNode *head2 = rev(l2);

       	// now do traversing to that list which is smaller in size
       	// we can't do null ka next so handle that

       	// make a dummy node
        int carry = 0;
        ListNode *dummynode = new ListNode(-1);
        ListNode *temp = dummynode;
        while (head1 != NULL && head2 != NULL)
        {
            int sum = head1->val + head2->val + carry;
            int remainder = sum % 10;
            carry = sum / 10;
            ListNode *newnode = new ListNode(remainder);
            temp->next = newnode;
           	// temp=temp->next;
            temp = newnode;
           	// or temp=dummynode;
            head1 = head1->next;
            head2 = head2->next;
        }


        while (head1 != NULL)
        {
            // iss loop me aaya hai it means head 2 null ho gaya
            
            int sum = head1->val+carry;
            int remainder = sum % 10;
            carry = sum / 10;
            ListNode*newnode=new ListNode(remainder);
            temp->next=newnode;
            temp=newnode;
            head1 = head1->next;
        }
        
          while (head2 != NULL)
        {
            int sum = head2->val + carry;
            int remainder = sum % 10;
            carry = sum / 10;
             ListNode*newnode=new ListNode(remainder);
            temp->next=newnode;
            temp=newnode;
            head2 = head2->next;
        }
        
        while(carry!=0)
        {
            
            int sum=carry;

            int remainder=sum%10;

            ListNode *newnode=new ListNode(remainder);

            temp->next=newnode;

            temp=newnode;

            carry=sum/10;
        }
        ListNode*ans=rev(dummynode->next);
        return ans;
    }
};
