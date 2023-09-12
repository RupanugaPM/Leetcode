class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(27,0);
        for(auto a:s){
            v[a-'a']++;
        }
        vector<int>a;
        for(auto el:v){
            if(el!=0){
                a.push_back(el);
            }
        }
        sort(a.begin(),a.end());
        int ans=0;
        set<int>ss;
        ss.insert(a.back());
        for(int i=a.size()-2;i>=0;i--){
            while(a[i]>0 && ss.find(a[i])!=ss.end()){
                a[i]--;
                ans++;
            }
            ss.insert(a[i]);
        }
        return ans;
    }
};