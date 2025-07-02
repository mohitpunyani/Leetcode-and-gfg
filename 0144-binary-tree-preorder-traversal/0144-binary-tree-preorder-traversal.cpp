/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int>ans;
stack<TreeNode*>st;

//    void recur(TreeNode*root){
//     if(root==NULL){
//         return;
//     }
//     ans.push_back(root->val);
//     recur(root->left);
//     recur(root->right);
//     return ;
//    }

void iter(TreeNode*root){
    TreeNode*curr=root;
    while(curr!=NULL){
        ans.push_back(curr->val);
        st.push(curr);
        curr=curr->left;
    }
    while(!st.empty()){
        curr=st.top();
        st.pop();
        curr=curr->right;
        while(curr!=NULL){
            ans.push_back(curr->val);
            st.push(curr);
            curr=curr->left;
        }
    }
    return;
}
    vector<int> preorderTraversal(TreeNode* root) 
    {
        // RECURSIVE

        // recur(root);
        // return ans;

        // ITERATIVE
        iter(root);
        return ans;
        
    }
};