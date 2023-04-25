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
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        // using with the help of vector (APPROACH 1) using o(n) space
        
        vector<int>v;
        Node*temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->data);
            temp=temp->next;
        }
        
        // now the question will become of array (means that array is palindrome or not)
        
        // do reverse the array
       
       int low=0;
       int high=v.size()-1;
       while(low<high){
           if(v[low]!=v[high]){
               return false;
           }
           low++;
           high--;
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