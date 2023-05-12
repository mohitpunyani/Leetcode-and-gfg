//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution
{
    public:
    
    vector<int>ans1;
    vector<int>ans2;
    void convert_into_second_tree(Node*root){
        
        if(root==NULL){
            return ;
        }
        
        convert_into_second_tree(root->left);
        convert_into_second_tree(root->right);
        swap(root->left,root->right);
        return ;
    }
    void inorder(Node*root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        return ;
    }
    int areMirror(Node* a, Node* b)
    {
        // Your code here
        
        // convert one tree into another tree and then find the inorder traversal of the trees 
        
        convert_into_second_tree(a);
        inorder(a,ans1);
        inorder(b,ans2);
        
        int ans=1;
        for(int i=0;i<ans1.size();i++){
            if(ans2[i]!=ans1[i]){
                ans=0;
                break;
            }
            else{
             continue;   
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);

        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);

        Solution ob;
        cout << ob.areMirror(root1, root2) << "\n";
    }
    return 0;
}
// } Driver Code Ends