//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
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

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node *node) {
    if (node == NULL) return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}


// } Driver Code Ends
// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
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
    // Function to convert a binary tree into its mirror tree.
    
    void mirror(Node* node)
    {
        // code here
        
        // NOTE -> USING RECURSION IS A BOTTOM UP APPROACH 
        
        // if(node==NULL){
        //     return ;
        // }
        // mirror(node->left);
        // mirror(node->right);
        // swap(node->left,node->right);
        // return ;
        
        
        // iterative approach  can be done using both stack and queue but queue approach first
        
        //  comes in mind
        
        // queue<Node*>q;
        // Node*temp=node;
        // q.push(node);
        // while(!q.empty()){
            
        //     int size=q.size();
            
        //     while(size--)
        //     {
                
        //       temp=q.front();
        //       q.pop();
        //     //   Node *t;
        //     //   t=temp->right;
        //     //   temp->right=temp->left;
        //     //   temp->left=t; 
              
        //       swap(temp->left,temp->right);
              
              
        //         //   if(temp->right!=NULL){
        //         //     q.push(temp->right);
        //         // }
        //         if(temp->left!=NULL){
        //             q.push(temp->left);
        //         }
        //         if(temp->right!=NULL){
        //             q.push(temp->right);
        //         }
                
        //     }
            // swap(temp->left,temp->right); 
            
            // WE HAVE TO SWAP FIRST . UNDERSTANDING BY DOING THIS DRY RUN 
            
            
            
            // iterative approach using stack
            
            
            // NOTE -> USING STACK IS A TOP DOWN APPROACH 

            // stack<Node*>st;
            // Node*temp=node;
            // st.push(temp);
            // while(!st.empty())
            // {
            //     temp=st.top();
            //         st.pop();
            //         if(temp->left!=NULL){
            //             st.push(temp->left);
            //         }
            //         if(temp->right!=NULL){
            //             st.push(temp->right);
            //         }
            //     swap(temp->left,temp->right);
            // }

        
        
          queue<Node*>q;
        Node*temp=node;
        q.push(node);
        while(!q.empty()){
            
            int size=q.size();
            
           
                
              temp=q.front();
              q.pop();
                  if(temp->right!=NULL){
                    q.push(temp->right);
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                // if(temp->right!=NULL){
                //     q.push(temp->right);
                // }
                
            swap(temp->left,temp->right);
        }
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        ob.mirror(root);
        inOrder(root);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends