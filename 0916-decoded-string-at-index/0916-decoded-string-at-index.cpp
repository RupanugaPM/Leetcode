class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long sz=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                sz*=(s[i]-'0');
            }
            else{
                sz++;
            }
        }
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            k%=sz;
            if(k==0 && s[i]>='a' && s[i]<='z'){
                string ans;
                ans+=s[i];
                return ans;
            }
            if(s[i]>='a' && s[i]<='z'){
                sz--;
            }
            else{
                sz/=(s[i]-'0');
            }
        }
        return "";
    }
};