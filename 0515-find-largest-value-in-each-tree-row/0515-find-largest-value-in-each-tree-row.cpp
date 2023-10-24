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
    void dfs1(TreeNode* root,int h,int &mh){
        mh=max(h,mh);
        if(root->left!=nullptr) dfs1(root->left,h+1,mh);
        if(root->right!=nullptr) dfs1(root->right,h+1,mh);
    }
    void dfs2(TreeNode* root,int h,vector<int>&v){
        v[h]=max(v[h],root->val);
        if(root->left!=nullptr) dfs2(root->left,h+1,v);
        if(root->right!=nullptr) dfs2(root->right,h+1,v);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr) return {};
        int mh=0;
        dfs1(root,0,mh);
        vector<int>v(mh+1,INT_MIN);
        dfs2(root,0,v);
        return v;
    }
};