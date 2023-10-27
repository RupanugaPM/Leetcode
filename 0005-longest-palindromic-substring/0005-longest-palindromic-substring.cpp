vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}
class Solution {
public:
    string longestPalindrome(string s) {
        vector<int>v = manacher(s);
        int ans=0;
        int ansv=0;
        int l=0,r=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>ansv){
                ansv=v[i];
                ans=i;
            }
        }
        
        if(ans%2==1){
            l=(ans)/2-v[ans]/2+1;
            r=(ans)/2+v[ans]/2;
        }
        else{
            l=ans/2-v[ans]/2+1;
            r=ans/2+v[ans]/2-1;
        }
        string sans;
        for(int i=l;i<=r;i++){
            sans+=s[i];
        }
        return sans;
    }
};