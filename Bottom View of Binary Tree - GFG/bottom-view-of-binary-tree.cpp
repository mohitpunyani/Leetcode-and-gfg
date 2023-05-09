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


vector <int> bottomView(Node *root);

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
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
  
  map<int,pair<int,int>>mp;
  
  // similarly approach to top view of binary tree
  
  // make a map of horizontal distance and pair of data and level
  vector<int>ans;
  void recursive(Node*root,int hd ,int level)
  {
      if(root==NULL){
          return ;
      }
      
    if(mp.count(hd)==0  ||  level>=mp[hd].second)
    {
       mp[hd]={root->data,level};
      }
      recursive(root->left,hd-1,level+1);
      recursive(root->right,hd+1,level+1);
      return ;
  }
    vector <int> bottomView(Node *root) 
    {
        // Your Code Here
        
        // iterative approach
        
        // queue<pair<Node*,int>>q;
        // q.push({root,0});
        // map<int,int>mp;
        // vector<int>ans;
        // while(!q.empty())
        // {
        //     int size=q.size();
        //     while(size--)
        //     {
        //         auto it=q.front();
        //         Node*temp=it.first;
        //         int hd=it.second;
        //         mp[hd]=temp->data;
        //         q.pop();

        //         if(temp->left!=NULL){
        //             q.push({temp->left,hd-1});
        //         }
        //         if(temp->right!=NULL){
        //             q.push({temp->right,hd+1});
        //         }
                
        //     }
        // }
        // for(auto it:mp){
            
        //     ans.push_back(it.second);
            
        //     // delete that value with the help of key 
            
        //     mp.erase(it.first);
        // }
        // if(mp.size()==0){
        //     return ans;
        // }
        
        
        // recursive approach 
        
        recursive(root,0,0);
        for(auto it:mp){
            ans.push_back(it.second.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

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
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends