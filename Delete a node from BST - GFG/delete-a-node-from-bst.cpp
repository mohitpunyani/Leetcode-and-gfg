//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to delete a node from BST.


int minvalue(Node*root,int &min)
{
    
    while(root!=NULL)
    {
        min=root->data;
        root=root->left;
    }
    return min;
    
}
Node* node_to_be_deleted(Node*root,int X){
    
     if(root==NULL){
        return NULL;
    }
    if(root->data==X)
    {
        // three cases
        
        // case 1 -> deleted node have zero child or (leaf node)
        
        if(root->left==NULL && root->right==NULL)
        {
        
            delete root;
            return NULL;
        }
        
        // case 2 -> deleted node has  only 1 child , it may be left one or right one
        
        // when child is in right side
        
        if(root->left==NULL && root->right!=NULL)
        {
            Node*temp=root->right;
            delete root;
            return temp;
            
        }
        
        // when child is in left side
        
         if(root->left!=NULL && root->right==NULL)
        {
            Node*temp=root->left;
            delete root;
            return temp;
            
        }
        
        // case 3 -> deleted node  has two child 
        
        // using concept of predecessor
        
        // find the predeceesor of that node or means find the maximum value of left_subtree
        if(root->left!=NULL && root->right!=NULL)
        {
            // find predecessor
            
            int val=minvalue(root->right,root->data);
            root->data=val;
            root->right=node_to_be_deleted(root->right,val);
            return root;
        }
}
    else if(root->data>X)
    {
        // go to left part
        root->left=node_to_be_deleted(root->left,X);
        return root;
    }
    else{
        root->right=node_to_be_deleted(root->right,X);
        return root;
    }
    return root;
}
Node *deleteNode(Node *root, int X)
{
    // your code goes here
    
    if(root==NULL){
        return NULL;
    }
    root=node_to_be_deleted(root,X);
    return root;
}
