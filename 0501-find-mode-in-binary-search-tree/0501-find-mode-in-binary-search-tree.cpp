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
    void dfs(TreeNode* root,unordered_map<int,int>&mp){
        mp[root->val]++;
        if(root->left){
            dfs(root->left,mp);
        }
        if(root->right){
            dfs(root->right,mp);
        }
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        dfs(root,mp);
        vector<int>modes;
        int ma=0;
        for(auto el:mp){
            if(el.second>ma){
                ma=el.second;
                modes={el.first};
            }
            else if(el.second==ma){
                modes.push_back(el.first);
            }
        }
        return modes;
    }
};