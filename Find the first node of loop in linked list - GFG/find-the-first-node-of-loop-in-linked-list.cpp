//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    
    Node*help=NULL;
    // this is used to store the address of fast when we get a cycle
    
     //Function to find first node if the linked list has a loop.
     
      bool detectLoop(Node* head)
    {
        // your code here
        
        Node*slow=head;
        Node*fast=head;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            if(slow==fast)
            {
                help=fast;
                return true;
            }
        }
        if(fast==NULL){
            return false;
        }
        
        
    }
    int find(Node*head,Node*slow,Node*fast)
    {
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow->data;
        
        
    }
    int findFirstNode(Node* head)
    {
        // your code here
        bool ans=detectLoop(head);
        Node*slow=head;
        if(ans==false)
        {
            // it means there is no cycle
            return -1;
        }
        else{
            int value=find(head,slow,help);
            return value;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends