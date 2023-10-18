class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m=relations.size();
        map<int,int>mp;
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++){
            mp[relations[i][1]-1]++;
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }
        deque<int>dn(n,0);
        deque<int>qu;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                qu.push_back(i);
                dn[i]=time[i];
            }
        }   
        while(qu.size()!=0){
            int v=qu[0];
            for(int i=0;i<adj[v].size();i++){
                if(dn[v]+time[adj[v][i]]>dn[adj[v][i]]){
                    dn[adj[v][i]]=max(dn[v]+time[adj[v][i]],dn[adj[v][i]]);
                    qu.push_back(adj[v][i]);
                }
            }
            qu.pop_front();
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dn[i]);
        }
        return ans;
    }
};