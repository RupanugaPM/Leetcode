class Solution {
public:
    char findTheDifference(string s, string t) {
        int t1=0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        while(t1<s.size()){
            if(s[t1]==t[t1]){
                t1++;
            }
            else{
                break;
            }
        }
        return t[t1];
    }
};