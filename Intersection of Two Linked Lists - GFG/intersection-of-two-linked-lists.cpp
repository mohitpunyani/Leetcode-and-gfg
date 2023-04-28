//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        
        // here the linked list is not sorted so we have to use hash or map
        
        unordered_map<int,bool>visited;
        
        Node*dummynode=new Node(-1);
        Node*temp=dummynode;
        
        // first put all the elements of second linked list in the hash
        
        Node*temp2=head2;
        visited[temp2->data]=true;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
            visited[temp2->data]=true;
        }
        
        // now traverse map;
        
        while(head1!=NULL)
        {
            if(visited.find(head1->data)!=visited.end())
            {
                Node* newnode=new Node(head1->data);
                temp->next=newnode;
                temp=newnode;
                head1=head1->next;
            }
            else
            {
                head1=head1->next;
            }
        }
        return dummynode->next;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends