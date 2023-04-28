//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    
    struct Node *reverse(struct Node*head){
        Node*prev=NULL;
        Node*curr=head;
        while(curr!=NULL)
        {
            Node*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    struct Node* add(struct Node*head1,struct Node*head2)
    {
        Node*dummy=new Node(-1);
        Node*head=dummy;
        int carry=0;
        int sum=0;
        while(head1!=NULL && head2!=NULL)
        {
            // this loop is when both list is of equal length
            int firstvalue=head1->data;
            
            int secondvalue=head2->data;
            
            sum=carry+firstvalue+secondvalue;
            
            // modulo operator gives carry
            
            int digit=sum%10;
            
            Node*temp=new Node(digit);
            
            head->next=temp;
            
            head=head->next;
            
            carry=sum/10;
            
            head1=head1->next;
            
            head2=head2->next;
            
        }
        // manlo koi ek linked list choti hai toh uska head pahle null tak pahunch
        
        // jayega
        while(head1!=NULL)
        
        // means dusari linked list choti hai it means woh toh null tak pahunch gayi
        {
            int sum=head1->data+carry;
        
            int digit=sum%10;
            
            Node*temp=new Node(digit);
            head->next=temp;
            
            head=temp;
            carry=sum/10;
            
            head1=head1->next;
        }
        while(head2!=NULL){
            int sum=head2->data+carry;
            int digit =sum%10;
            Node*temp=new Node(digit);
            head->next=temp;
            head=head->next;
            carry=sum/10;
            head2=head2->next;
        }
        while(carry!=0)
        {
            int sum=carry;

            // int digit=sum%10;

            Node *temp=new Node(sum);

            head->next=temp;

            head=temp;
            carry=0;
            // carry=sum/10;
        }
        return dummy->next;
    }
    
    public:
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        // step 1 reverse the both linked list
        Node*head1=reverse(first);
        Node*head2=reverse(second);
        
        // step2 add both linked list and move pointer from left
        
        Node*ans=add(head1,head2);
        // step3 reverse the answer to get original linked list
        
        Node*originalhead=reverse(ans);
        return originalhead;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends