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
    TreeNode* constructFromPrePost1(vector<int>& pre,int l1,int r1, vector<int>& post,int l2,int r2) {
        if(l1 > r1 || l2 > r2 ){
            return NULL;
        }
        
        if(pre[l1]!=post[r2]){
            return NULL;
        }
        
        TreeNode * root = new TreeNode(pre[l1]);
        if(l1 == r1 && l2 == r2){
            return root;
        }
        
        int target = pre[l1+1];
        vector<int>::iterator it = find(post.begin()+l2,post.begin()+r2-1,target);
        if(it == post.end()){
            return NULL;
        }
        
        int half = it - (post.begin() + l2);
        root->left = constructFromPrePost1(pre,l1+1,l1+1+half,post,l2,l2+half);
        root->right = constructFromPrePost1(pre,l1+2+half,r1,post,l2+half+1,r2-1);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size() == 0 && post.size() == 0){
            return NULL;
        }
        int l1 = 0;
        int r1 = pre.size()-1;
        int l2 = 0;
        int r2 = post.size()-1;
        
        return constructFromPrePost1(pre,l1,r1,post,l2,r2);
    }
};