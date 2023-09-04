#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<vector<int>>distances;
map<pair<int,int>,int>mp;

void dfs(int v, int p,vector<int>vv)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    distances[v]=vv;
    for (int u : adj[v]) {
        if (u != p){
            vv[0]++;
            vv[mp[{u,v}]]++;
            dfs(u, v,vv);
            vv[0]--;
            vv[mp[{u,v}]]--;
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root,vector<int>v) {
    tin.resize(n,0);
    tout.resize(n,0);
    distances.resize(n,{});
    distances[root]=v;
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root,v);
}

class Solution {
public:
    vector<int> minOperationsQueries(int nn, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        adj.clear();
        adj.resize(nn,{});
        n=nn;
        mp.clear();
        for(auto el:edges){
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
            mp[{el[0],el[1]}]=el[2];
            mp[{el[1],el[0]}]=el[2];
        }
        vector<int>v(27,0);
        preprocess(0,v);
        vector<int>ans;
        for(auto el:queries){
            int u=el[0];
            int v=el[1];
            int lc=lca(u,v);
            int distuv=distances[u][0]+distances[v][0]-2*distances[lc][0];
            int ma=0;
            for(int i=1;i<27;i++){
                ma=max(ma,distances[u][i]+distances[v][i]-2*distances[lc][i]);
            }
            ans.push_back(distuv-ma);
        }
        return ans;
    }
};