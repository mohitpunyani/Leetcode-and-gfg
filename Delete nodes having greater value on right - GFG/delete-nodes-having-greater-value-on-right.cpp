//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        
   
        // here we have to play with three pointers
        
        //  i do dry run then i feel i have to play with three pointer and also need a dummy node
        
        // i also need dummy node;
        
        // solved for atleast three or more than three nodes
        
        // Node*dummynode=new Node(-1);
        // Node*prev=dummynode;
        // Node*curr=head;
        // Node*Next=curr->next;
        // while(Next!=NULL)
        // {
        //     if(Next->data>curr->data){
        //         Node*temp=curr;
        //         prev->next=curr->next;
        //         curr=Next;
        //         Next=Next->next;
        //         temp->next=NULL;
        //         delete temp;
        //     }
        //     else{
        //         prev=curr;
        //         curr=Next;
        //         Next=Next->next;
        //     }
            
        // }
        // return dummynode->next;
        
        // NOTE -> YEAH APPROACH ISLIYE GALAT HAI KYON KI ISESE APNE SIRF NEXT ELEMENT CHECK KAR RAHE 
        //  HAI AGAR HAI TOH LINK KAR DIYA , NAHI HAI TOH BADA DIYA 
        //  APNE KO EK ELEMENT KE LIYE SAARE ELEMENTS CHECK KARNE PADEGA
        
        // SO THAT'S WHY THIS IS A WRONG APPROACH
        
        // 1. we can modify this approach ki agar main har baar pointer ko head par le aayu jaise hi value badi
        
        // nikali aur phir wapas se check karu instead ki pointer ko aage bada do
        
        // in this approach we copy the links and value
        
        Node*curr=head;
        while(curr->next!=NULL){
            if(curr->data<curr->next->data)
            {
                Node*d=curr->next;
                curr->data=curr->next->data; // copy the data
                curr->next=curr->next->next; // copy the link
                d->next=NULL;
                delete d;
                curr=head; // temp ko wapis head par le aaye aur phir wapis shuru se check kiya
                head=curr;
            }
            else{
                curr=curr->next;
            }
        }
        
        return head;
        
        
        
        // 2. using stack
        
        
        
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends