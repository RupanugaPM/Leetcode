pair<int,int> dfs1(int v,int p,vector<vector<int>>&adj,vector<vector<pair<int,int>>>&dow,map<pair<int,int>,int>&mp){
    pair<int,int>rr={0,0};
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            pair<int,int> ret=dfs1(adj[v][i],v,adj,dow,mp);
            if(mp.find({v,adj[v][i]})!=mp.end()){
                ret.first++;
            }
            else{
                ret.second++;
            }
            dow[v][i]=ret;
            rr.first+=ret.first;
            rr.second+=ret.second;
        }
    }
    return rr;
}
void dfs2(int v,int p,vector<vector<int>>&adj,vector<vector<pair<int,int>>>&dow,pair<int,int> pans,map<pair<int,int>,int>&mp){
    pair<int,int>rr={0,0};
    rr=pans;
    for(int i=0;i<dow[v].size();i++){
        rr.first+=dow[v][i].first;
        rr.second+=dow[v][i].second;
    }
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs2(adj[v][i],v,adj,dow,{rr.first-dow[v][i].first+(mp.find({v,adj[v][i]})==mp.end()),rr.second-dow[v][i].second+(mp.find({v,adj[v][i]})!=mp.end())},mp);
        }
        else{
            dow[v][i]={pans.first,pans.second};
        }
    }
}

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<pair<int,int>>>dow(n);
        vector<int>ans(n,0);
        map<pair<int,int>,int>mp;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            dow[i[0]].push_back({0,0});
            dow[i[1]].push_back({0,0});
            mp[{i[0],i[1]}]++;
        }
        pair<int,int>pp={0,0};
        dfs1(0,-1,adj,dow,mp);
        dfs2(0,-1,adj,dow,pp,mp);
        for(int i=0;i<n;i++){
            int aa=0;
            for(int j=0;j<dow[i].size();j++){
                aa+=dow[i][j].second;
                cout<<dow[i][j].first<<" "<<dow[i][j].second<<" ";
            }
            cout<<endl;
            ans[i]=aa;
        }
        return ans;
    }
};