//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    
    map<int,pair<int,int>>mp;
    
    // map of horizontal distance and pair of data and level
    vector<int>ans;
    void recursive(Node*root,int hd,int level)
    {
        if(root==NULL){
            return ;
        }
        if(mp.find(hd)==mp.end())
        {
            // compare the levels
            
            mp[hd]={root->data,level};
        }
        recursive(root->left,hd-1,level+1);
        recursive(root->right,hd+1,level+1);
        return ;
    }
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
        // ITERATIVE APPROACH 
        
        //  using queue
        
        // sara khel levels ka hai
        
        // i do dry run we need a map in sorted order
        
        
        
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        vector<int>ans;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
            auto top=q.front();
            
            Node *temp=top.first;
            // horizontal distance hd
            int hd=top.second;
            q.pop();
            
            // mp.insert({hd,temp->data});
            if(mp.find(hd)==mp.end()){
                mp[hd]=temp->data;
            }
            if(temp->left!=NULL){
                q.push({temp->left,hd-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,hd+1});
            }
            }
        }
        for(auto &it:mp)
        {
            ans.push_back(it.second);
            // mp.erase(x);
        }
        if(mp.size()==0){
            return ans;
        }
        
        
        // RECURSIVE APPROACH 
        
        
        // recursive(root,0,0);
        
        // sort according to horizontal distance
        
        // for(auto it:mp){
        //     ans.push_back(it.second.first);
        // }
        // return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends