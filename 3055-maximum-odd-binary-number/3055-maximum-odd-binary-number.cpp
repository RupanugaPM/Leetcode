class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int x=count(s.begin(),s.end(),'1');
        
        int o=s.size()-x;
        x-=1;
        string ans;
        for(int i=0;i<x;i++){
            ans+='1';
        }
        for(int i=0;i<o;i++){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};