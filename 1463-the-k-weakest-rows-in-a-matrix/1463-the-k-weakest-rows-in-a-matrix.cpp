class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>vp(mat.size());
        for(int i=0;i<mat.size();i++){
            vp[i].second=i;
            for(int j=0;j<mat[0].size();j++){
                vp[i].first+=mat[i][j];
            }
        }
        sort(vp.begin(),vp.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vp[i].second);
        }
        return ans;

    }
};