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
        while(head2!=NULL && newhead!=NULL)
        {
            if(head2==newhead)
            {
                ans=head2->data;
                return ans;
                
            }
            else{
              head2=head2->next;
              newhead=newhead->next;
            }            
        }
        return ans;
    }
    else if(l2>l1)
    {
         Node*newhead=chalaya(head2,diff);
        // ab dono ko equal chalaya
        while(head1!=NULL && newhead!=NULL)
        {
            if(head1==newhead)
            {
                ans=head1->data;
                return ans;
            }
            else{
            head1=head1->next;
            newhead=newhead->next;
            }
            
        }
        return ans;
    }
    
    else if(l1==l2)
    {
        while(head1!=NULL && head2!=NULL){
            if(head1==head2){
                ans=head1->data;
                return ans;
            }
            else{
                head1=head1->next;
                head2=head2->next;
            }
        }
        return ans;
        
    }
    
}

