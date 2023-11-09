class Solution {
public:
    int countHomogenous(string s) {
        long long int x=0;
        long long int c=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                c++;
            }
            else{
                x+=(c*(c+1))/2;
                c=1;
            }
        }
        x+=(c*(c+1))/2;
        return int(x%(int(1e9+7)));
    }
};