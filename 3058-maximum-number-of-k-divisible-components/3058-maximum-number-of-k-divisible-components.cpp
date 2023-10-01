int dfs(int v,int p,vector<vector<int>>&adj,vector<int>&values,int &ans,int &k){
    int val=0;
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            val+=dfs(adj[v][i],v,adj,values,ans,k);
        }
    }
    val+=values[v];
    if(val%k==0){
        ans++;
        return 0;
    }
    return val;
}

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=0;
        dfs(0,-1,adj,values,ans,k);
        return ans;

    }
};