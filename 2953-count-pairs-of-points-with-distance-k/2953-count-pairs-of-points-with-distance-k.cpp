class Solution {
public:
    int countPairs(vector<vector<int>>& v, int k) {
        map<pair<int,int>,int>mp;
        int n=v.size();
        for(int i=0;i<n;i++){
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                if(mp.find({v[i][0]^j,v[i][1]^(k-j)})!=mp.end()){
                    ans+=mp[{v[i][0]^j,v[i][1]^(k-j)}];
                }
            }
            mp[{v[i][0],v[i][1]}]++;
        }
        return ans;
    }
};