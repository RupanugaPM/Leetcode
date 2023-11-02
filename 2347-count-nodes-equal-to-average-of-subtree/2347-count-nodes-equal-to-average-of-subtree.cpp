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
    pair<int,int> dfs(TreeNode* root,int &ans){
        pair<int,int> su={root->val,1};
        int x=root->val;
        if(root->left){
            pair<int,int>p1=dfs(root->left,ans);
            su.first+=p1.first;
            su.second+=p1.second;
        }
        if(root->right){
            pair<int,int>p1=dfs(root->right,ans);
            su.first+=p1.first;
            su.second+=p1.second;
        }
        if(su.first/su.second==x){
            ans++;
        }
        return su;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};