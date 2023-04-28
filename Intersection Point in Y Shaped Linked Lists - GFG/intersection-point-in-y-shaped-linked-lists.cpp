//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.

int lengthofll(Node*head,int count)
{
    while(head->next!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

Node* chalaya(Node*head,int diff)
{
    while(diff!=0)
    {
        diff--;
        head=head->next;
    }
    return head;
    
}
int dono_ko_equalchalaya(Node*head,Node*newhead)
{
      int ans=-1;
      while(head!=NULL && newhead!=NULL)
        {
            if(head==newhead)
            {
                ans=head->data;
                return ans;
                
            }
            else{
              head=head->next;
              newhead=newhead->next;
            }            
        }
        return ans;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    // isme length ka khel hai
    
    int l1=lengthofll(head1,1);
    int l2=lengthofll(head2,1);
    int ans=-1;
    int diff=abs(l1-l2);
    // jiski length jayada hai usko utane kadam chalade 
    if(l1>l2)
    {
        Node*newhead=chalaya(head1,diff);
        // ab dono ko equal chalaya
        int data=dono_ko_equalchalaya(head2,newhead);
        return data;
       
    }
    else if(l2>l1)
    {
         Node*newhead=chalaya(head2,diff);
        // ab dono ko equal chalaya
        int data=dono_ko_equalchalaya(head1,newhead);
        return data;

    }
    
    else if(l1==l2)
    {
        int data=dono_ko_equalchalaya(head1,head2);
        return data;
        
    }
    
}

