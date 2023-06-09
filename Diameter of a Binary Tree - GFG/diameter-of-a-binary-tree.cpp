//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
  
  int maxi=0;
  
  // FOR APPROACH 1
  
  
//   int recursiveheight(Node* &root)
//     {
//         if(root==NULL){
//             return 0;
//         }
//         else{
//           int left_height=recursiveheight(root->left);
//           int right_height=recursiveheight(root->right);
//           int ans=1+max(left_height,right_height);
//           return ans;
             
//         }
//     }



   //  FOR APPROACH 2 

     int recursiveheight2(Node* root)
    {
        if(root==NULL){
            return 0;
        }
        else{
          int left_height=recursiveheight2(root->left);
          int right_height=recursiveheight2(root->right);
          maxi=max(maxi,left_height+right_height+1);
          
          return 1+max(left_height,right_height);
             
        }
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) 
    {
        // Your code here
        
         // APPROACH 1 -> using height function 
         
         
         
        //  if(root==NULL)
        //  {
        //      return 0;
             
        //  }
         // find the height for the left and reight 
         
        //  // option 1
        //  int left_diameter=diameter(root->left);
        //  // option 2
        //  int right_diameter=diameter(root->right);
         
        //  // option 3
         
        //  int left_height=recursiveheight(root->left);
        //  int right_height=recursiveheight(root->right);
         
        //  int ans=left_height+right_height;
         
        //  return max(1+ans,max(left_diameter,right_diameter));
        
        
        
        // APPROACH 2 -> OPTIMIZED THROUGH APPROACH 1.
        
        recursiveheight2(root);
        return maxi;
        
        // APPROACH 3 -> IT IS IMPORTANT APPROACH
        
        
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends