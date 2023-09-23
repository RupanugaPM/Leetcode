bool cmp(string &s1,string &s2)
{
    return s1.size() < s2.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int>mp;
        int ans=0;
        for(int i=0;i<words.size();i++){
            mp[words[i]]=1;
            for(int j=0;j<words[i].size();j++){
                string s;
                for(int k=0;k<words[i].size();k++){
                    if(k!=j){
                        s+=words[i][k];
                    }
                }
                if(mp.find(s)!=mp.end()){
                    mp[words[i]]=max(mp[s]+1,mp[words[i]]);
                }
            }
            ans=max(ans,mp[words[i]]);
        }
        return ans;
    }
};