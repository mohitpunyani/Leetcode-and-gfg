//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<bits/stdc++.h>

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node* middleofll(Node*head){
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
        }
        return slow;
    }
    Node*rev(Node*head){
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
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        // using with the help of vector (APPROACH 1) using o(n) space
        
    //     vector<int>v;
    //     Node*temp=head;
    //     while(temp!=NULL)
    //     {
    //         v.push_back(temp->data);
    //         temp=temp->next;
    //     }
        
    //     // now the question will become of array (means that array is palindrome or not)
        
    //     // do reverse the array
       
    //   int low=0;
    //   int high=v.size()-1;
    //   while(low<high){
    //       if(v[low]!=v[high]){
    //           return false;
    //       }
    //       low++;
    //       high--;
    //   }
    //   return true;
       
       // this is my approach
       
       
       // Approach 2 ( WITHOUT CONVERTING INTO VECTOR OR WITHOUT USING EXTRA SPACE)
       
       // play with links
       
       Node* middle=middleofll(head);
       
       // ab middle ke badd wali list ko reverse kar
       
       Node* newhead=rev(middle);
       
       // now we have two different linked lists compare the data
       
       Node*temp=newhead;
       
       while(temp!=NULL)
       {
           if(temp->data!=head->data){
               return false;
           }
          
           temp=temp->next;
           head=head->next;
           
       }
       return true;
    }
       
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends