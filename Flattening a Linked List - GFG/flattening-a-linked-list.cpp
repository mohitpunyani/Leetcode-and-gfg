//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

   void merge(Node* head1, Node* head2)  
{  
    // code here
    Node*dummynode=new Node(-1);
    Node*temp=dummynode;
    Node*curr1=head1;
    Node*curr2=head2;
    
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data<=curr2->data)
        {
            temp->bottom=curr1;
            temp=curr1;
            curr1=curr1->bottom;
            
        }
        else{
            temp->bottom=curr2;
            temp=curr2;
            curr2=curr2->bottom;
        }
       
    }
    while(curr1!=NULL){
        temp->bottom=curr1;
        temp=temp->bottom;
        curr1=curr1->bottom;
    }
    while(curr2!=NULL){
        temp->bottom=curr2;
        temp=temp->bottom;
        curr2=curr2->bottom;
    }
    return ;
} 
Node *flatten(Node *root)
{
   // Your code here
   
      // Your code here
    Node *nexty=root->next;
    while(nexty!=NULL){
        merge(root,nexty);
        nexty=nexty->next;
        
    }
    return root;
   
}

