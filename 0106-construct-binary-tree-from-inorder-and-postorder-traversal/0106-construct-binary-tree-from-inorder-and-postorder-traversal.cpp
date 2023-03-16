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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int& postIndex,int i,int j,unordered_map<int,int>& m){
          if(i>j || postIndex<0 ){
              ++postIndex;
              return NULL;
          }
                
        TreeNode* curr=new TreeNode(postorder[postIndex]);
        int ix=m[postorder[postIndex]]; 
        
        curr->right=solve(postorder,inorder,--postIndex,ix+1,j,m);
        curr->left=solve(postorder,inorder,--postIndex,i,ix-1,m);
        
        
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        int s=inorder.size();
        for(int i=0;i<s;i++){
            m[inorder[i]]=i;
        }
        
        int postIndex=s-1;
        return solve(postorder,inorder,postIndex,0,s-1,m);
    }
};