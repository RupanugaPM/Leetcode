class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        map<int,vector<int>>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]].push_back(i);
        }
        vector<vector<int>>ans={{}};

        for(auto el:mp){
            for(int i=0;i<el.second.size();i++){
                ans[ans.size()-1].push_back(el.second[i]);
                if(ans.back().size()==el.first){
                    ans.push_back({});
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};