class Solution {
public:
    int dfs(int v,int p,vector<vector<int>>&adj,vector<int>&coins,int &k,vector<int>&tot,int t){
        if(t>14){
            return 0;
        }
        if(tot[v]>t){
            return 0;
        }
        tot[v]++;
        int n1=(coins[v]>>t)-k,n2=coins[v]>>(t+1);
        for(auto c:adj[v]){
            if(c!=p){
                n1+=dfs(c,v,adj,coins,k,tot,t);
                n2+=dfs(c,v,adj,coins,k,tot,t+1);
            }
        }
        return max(n1,n2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=0;
        for(int i=0;i<edges.size();i++){
            n=max(n,max(edges[i][0],edges[i][1]));
        }
        n++;
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>tot(n,0);
        return dfs(0,-1,adj,coins,k,tot,0);
    }
};