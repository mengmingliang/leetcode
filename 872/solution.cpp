/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getTreeLeaf(TreeNode *root,vector<TreeNode *> &leafs){
        if(root == NULL){
            return false;
        }
        
        if(!root->left && !root->right){
            leafs.push_back(root);
            return true;
        }
        
        if(root->left){
            getTreeLeaf(root->left,leafs);
        }
        if(root->right){
            getTreeLeaf(root->right,leafs);
        }
        
        return false;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode *> leafs1;
        vector<TreeNode *> leafs2;
        
        getTreeLeaf(root1,leafs1);
        getTreeLeaf(root2,leafs2);
        
        if(leafs1.size()!=leafs2.size()){
            return false;
        }
        
        for(int i = 0;i < leafs1.size(); ++i){
            if(leafs1[i]->val != leafs2[i]->val){
                return false;
            }
        }
        
        return true;
    }
};