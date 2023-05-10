//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    
    // int ans=INT_MIN;
    // //Function to check whether a binary tree is balanced or not.
    
    // //  NOTE ->  similar like diameter question 
    // int height(Node*root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int left_height=height(root->left);
    //     int right_height=height(root->right);
    //     ans=1+max(left_height,right_height);
    //     return ans;
    // }
    
    // pair approach like diameter quesiton 
    
    // NOTE -> THIS APPROACH IS DEVELOPED FROM RECURSION APPROACH 
    
    //  make a pair of int and bool or height and isbalanced
    
    pair<int,bool> solve(Node*root)
    {
        if(root==NULL){
            pair<int,bool>p={0,true};
            return p;
        }
        pair<int,bool>left=solve(root->left);
        
        pair<int,bool>right=solve(root->right);
        
        // now we have three options
        
        // option 1 left subtree
        bool op1=left.second;
        
        // option 2 right subtree
        bool op2=right.second;
        
        // option 3 find height
        
        bool op3=abs(left.first-right.first)<=1;
        pair<int,bool>ans;
        ans.first=1+max(left.first,right.first);
        if(op1 && op2 && op3)
        {
            ans.second=true;
        }
        else{
            ans.second=false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
    //     if(root==NULL){
    //         return true;
    //     }
        
    //     //  option 1
    //     bool isBalanced_left_subtree=isBalanced(root->left);
        
    //     if(isBalanced_left_subtree==false){
    //         return false;
    //     }
    //     // option 2 
    //     bool isBalanced_right_subtree=isBalanced(root->right);
    //     if (isBalanced_right_subtree==false){
    //         return false;
    //     }
    //     // option 3 find height for both left and right subtree 
        
    //     int left_height=height(root->left);
    //     int right_height=height(root->right);
        
    //     bool difference=abs(left_height-right_height)<=1;
        
    //     if(difference==true  && isBalanced_left_subtree==true && isBalanced_right_subtree==true)
    //     {
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    
    return solve(root).second;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends