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
    vector<TreeNode*> allPossibleFBT(int N) {
        map<int,vector<TreeNode *>> dp;
        vector<TreeNode *> ans;
        
        if(N%2 == 0){
            return ans;
        }
        
        /*one*/
        TreeNode * root = new TreeNode(0);
        vector<TreeNode *> one;
        one.push_back(root);
        dp[1] = one;
        
        
        for(int i = 3;i <= N; i = i+2){
            vector<TreeNode *> level;
            for(int j = 1;j < i; j = j+2){
               int left = j;
               int right = i-1-j;
               for(int m = 0;m < dp[left].size();++m){
                   for(int n = 0;n < dp[right].size();++n){
                       TreeNode * node = new TreeNode(0);
                       node->left = dp[left][m];
                       node->right = dp[right][n];
                       level.push_back(node);
                   }
               }
            }
            dp[i] = level;
        }
        
        return dp[N];
    }
};