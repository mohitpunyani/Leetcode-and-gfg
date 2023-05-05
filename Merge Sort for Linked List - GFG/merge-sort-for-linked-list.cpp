//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


// class Solution{
//   public:
  
//   Node* middle(Node *head)
//     {
//         // using slow and fast pointer theorm
//         Node*slow=head;
//         Node*fast=head->next;
//         while(fast->next!=NULL && fast!=NULL)
//         {
//             fast=fast->next->next;
//             // if(fast->next!=NULL){
//             //     fast=fast->next;
//             // }
//             slow=slow->next;
//         }
//         return slow;
        
//     }
//   Node* merge(Node* head1, Node* head2)  
// {  
//     // code here
//     Node*dummynode=new Node(-1);
//     Node*temp=dummynode;
//     Node*curr1=head1;
//     Node*curr2=head2;
    
//     while(curr1!=NULL && curr2!=NULL)
//     {
//         if(curr1->data<=curr2->data)
//         {
//             temp->next=curr1;
//             temp=curr1;
//             curr1=curr1->next;
            
//         }
//         else{
//             temp->next=curr2;
//             temp=curr2;
//             curr2=curr2->next;
//         }
       
//     }
//     while(curr1!=NULL){
//         temp->next=curr1;
//         temp=temp->next;
//         curr1=curr1->next;
//     }
//     while(curr2!=NULL){
//         temp->next=curr2;
//         temp=temp->next;
//         curr2=curr2->next;
//     }
//     return dummynode->next;
// }
//     //Function to sort the given linked list using Merge Sort.
//     Node* mergeSort(Node* head)
//     {
//         // your code here
        
//         // similary like to sort array using merge sort
        
//         // here we have find middle in different way
//           if(head==NULL || head->next==NULL)
//         {
//         return head;
//         }
//         Node *curr=head;
//         Node *left=NULL;
//         Node *right=NULL;
//         Node* mid=middle(curr);
//         left=head;
//         right=mid->next;
//         mid->next=NULL;
//         left=mergeSort(left); // left call
//         right=mergeSort(right); // right call
//         Node *ans=merge(left,right); // complete call
//         return ans;
        
//     }
// };


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *middle(Node *head)
    {
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            // fast=fast->next->next;
        }
        return slow;
    }
    Node *merge(Node* left,Node* right)
    {
        Node *curr=new Node(-1);
        Node *temp=curr;
        if(left==NULL)
        return right;
        if(right==NULL)
        return left;
        while(left!=NULL && right !=NULL)
        {
            if(left->data<right->data)
            {
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else
            {
                 temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        while(left!=NULL)
        {
             temp->next=left;
                temp=left;
                left=left->next;
        }
        while(right!=NULL)
        {
             temp->next=right;
                temp=right;
                right=right->next;
        }
        return curr->next;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
        {
        return head;
        }
        Node *curr=head;
        Node *left=NULL;
        Node *right=NULL;
        Node* mid=middle(curr);
        left=head;
        right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        Node *ans=merge(left,right);
        return ans;
    }
};

//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends