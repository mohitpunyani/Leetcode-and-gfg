//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
#include<bits/stdc++.h>
using namespace std;
void inorder(Node*root,vector<int>&ans){
    
    if(root==NULL){
        return ;
    }
    inorder(root->left,ans);
    ans.push_back(root->key);
    inorder(root->right,ans);
    return ;
}


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here

// approach 1 -> bad approach 

// vector<int>ans;
// inorder(root,ans);
// pre=NULL;
// suc=NULL;
// int index;
// for(int i=0;i<ans.size();i++){
//     if(ans[i]<key)
//     {
//         pre=new Node(ans[i]);
//     }
//     if(ans[i]>key){
//         suc=new Node(ans[i]);
//         break;
//     }
// }


// approach 2 -> good approach 

// NOTE-> IT'S A VERY GOOD QUESTION 


// THIS IS A SUB PART OF MIN AND MAX IN BST , first find that key

//  predecessor means left_subtree me maximum element
//  successor means right_subtree me minimum element

// Node*curr=root;

// main task is to find the key

   Node*temp=root;

   pre=NULL;
   suc=NULL;

 
    while(temp!=NULL){

         if(key==temp->key)

         {

             break;

         }

         else if(temp->key>key){

 

            suc=temp;

 

            temp=temp->left;

 

        }

 

        else{

 

            pre=temp;

 

            temp=temp->right;

 

        }

 

    }

 

    if(temp==NULL)

    {

        return;

    }

    Node*leftree=temp->left;

 

    while(leftree!=NULL){

 

        pre=leftree;

        leftree=leftree->right;

 

    }

 

    Node*rightree=temp->right;

 

    while(rightree!=NULL){

 

        suc=rightree;

 

        rightree=rightree->left;

 

    }


}