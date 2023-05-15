//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
  
//   int count=0;
 
    // void solve(Node*root,int sum ,int k){
        
    //     if(root==NULL){
    //         return ;
    //     }
    //     sum=sum+root->data;
    //     if(sum==k){
    //         count++;
    //     }
    //     solve(root->left,sum,k);
    //     solve(root->right,sum,k);
    //     return ;
    // }
    
    // 2ND APPROACH 
    
        int count=0;
        void sumKHelper(Node *root, int k, unordered_map<long long, int> &mp, long long currSum) {
        if(root == NULL)
           return ;
        
        currSum += root->data;
        
        if(mp.find(currSum-k) != mp.end())
           count += mp[currSum-k];
        
        mp[currSum]++;
        sumKHelper(root->left, k, mp,  currSum);
        
        sumKHelper(root->right, k, mp,  currSum);
        
        mp[currSum] -= 1;
        currSum -= root->data;
        

    }
  

    int sumK(Node *root,int k)
    {
        // code here 
        
        // good thought (question ko dekhte hi map dimaag me aaya)
        
        // (IMP)  lakin usese pahle ek approach aur aayi thi, common thinking(in this type of question
        //  THIS APPROACH IS VERY COMMON)
        
        // approach 1 
        
        // if(root==NULL){
        //     return 0;
        // }
        // solve(root,0,k);
        
        // //  in every left or right call the do the sum variable to zero and calculate sum every time
        // sumK(root->left,k);
        // sumK(root->right,k);
        // return count;
        
        // approach 2 -> using map made from approach 1 
        
        // NOTE(IMP)  -> APPROACH OF THIS QUESTION IS SIMILAR TO SUBARRAY WITH ZERO  SUM 
        // USING MAP
     
       unordered_map<long long, int> mp;
        mp[0]=1;
        long long currSum = 0;
    
        sumKHelper(root, k, mp,  currSum);
        return count;
        // appraoch 3 ->
    }
};




//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends