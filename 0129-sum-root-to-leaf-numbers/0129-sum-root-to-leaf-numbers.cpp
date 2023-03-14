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
    
    int total_sum=0;
    int sumNumbers(TreeNode* root)
    {
        // right wale par calculation baad me hogi pahle left wale ka soch
        
        
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        
        while(!st.empty())
        
        {
            
            pair<TreeNode*,int> p=st.top();
            
            st.pop();
            TreeNode*curr_node=p.first;
            
            int curr_sum=p.second;
            curr_sum=curr_sum*10+curr_node->val;
                
           if(curr_node->left==NULL && curr_node->right==NULL)
           {
                    total_sum=total_sum+curr_sum;
           }
            if(curr_node->left!=NULL){
                st.push({curr_node->left,curr_sum});
            }
            if(curr_node->right!=NULL){
                st.push({curr_node->right,curr_sum});
            }
            
        }
        return total_sum;
    }
};