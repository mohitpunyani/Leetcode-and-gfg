//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// } Driver Code Ends
/* A binary tree node

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

class Solution
{
    public:
  // MY APPROACH 
// bool helper(Node *root , vector<int> & v ,  int target){

//         if(root==NULL)
//         return false;


      
//         v.push_back(root->data);

//       if(root->data==target) return true;
        
//       bool lh=  helper(root->left , v, target);
      
//       bool rh= helper(root->right , v, target);
      
//       if(lh==false && rh==false) 
//       {
//           // it means that we reach the leaf node
//           v.pop_back(); return false;
//       } 
//       else if((lh==true && rh==false) or (rh==true && lh==false))
//       {
//           return true;
//       }
      


//     }
    
    Node * solve(Node* root ,int n1 ,int n2)
    {
        if(root==NULL){
            return root;
        }
        if(root->data==n1 or root->data==n2){
            return root;
        }
        
        Node * left = solve(root->left,n1,n2);
        Node * right = solve(root->right,n1,n2);
        if(left==NULL && right==NULL){
            return NULL;
        }
      if(left ==NULL && right!=NULL){
            return right;
        }
        else if(left!=NULL && right==NULL){
            return left;
        }
        else if(left!=NULL && right!=NULL){
            return root;
        }
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
      
       // approach 1 -> directly comes in my mind
       
    // vector<int> v , v1;

    //   helper(root , v , n1);

    //   helper(root , v1 , n2);


    //   int m=min(v.size() , v1.size());

    //   for(int i=m-1; i>=0;i--){

    //       if(v[i]==v1[i]) 
    //       {
    //           Node*ans=new Node(v[i]);
    //           return ans;
    //           break;
    //       }
    //   }

    //   return root;
      
      // approach 2 -> good approach 
              return solve(root,n1,n2);

      
      
    }
};

//{ Driver Code Starts.

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}

// } Driver Code Ends