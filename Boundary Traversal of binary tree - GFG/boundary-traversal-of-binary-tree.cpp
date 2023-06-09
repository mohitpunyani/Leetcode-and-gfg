//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


class Solution {
public :
    void left(Node*root,vector<int> &ans)
    {
        if((root==NULL) or (root->left==NULL && root->right==NULL))
        {
            return ;
        }
        ans.push_back(root->data);
        
        // here prefer left subtree over right subtree
        if(root->left!=NULL){
            left(root->left,ans);
        }
        if(root->left==NULL)
        {
            // agar root->left is  null toh hi jaana hai right me

            // I conclude this point using dry run 
            
            left(root->right,ans);
        }
        
        
        // do dry run these will give you mistake
        
        // left(root->left,ans);
        // left(root->right,ans);
        
        return ;
    }
    void leaf(Node*root,vector<int> &ans)
    {
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
        return ;
    }
    void right(Node*root,vector<int> &ans)
    {
        if((root==NULL) or (root->left==NULL && root->right==NULL))
        {
            return ;
        }
         // priority will me given to right subtree over left subtree
         if(root->right!=NULL){
             right(root->right,ans);
         }
         if(root->right==NULL){
             right(root->left,ans);
         }
        ans.push_back(root->data);
        return ;
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        // make three function
        // 1. which print left part except all leaf nodes
        
        // 2. which print all leaf nodes 
        
        // 3. which print all right part in reverse order except all leaf nodes.
        
        vector<int> ans;
        if(root->left==NULL && root->right==NULL)
        {
            // this means that we have only single nodes
            
            ans.push_back(root->data);
            return ans;
        }
        ans.push_back(root->data);
        left(root->left,ans);
        leaf(root->left,ans);
        leaf(root->right,ans);
        right(root->right,ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends