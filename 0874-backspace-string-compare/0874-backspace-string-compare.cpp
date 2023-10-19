class Solution {
public:
    string func(string &s){
        string a;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(a.size()>0){
                    a.pop_back();
                }
            }
            else{
                a+=s[i];
            }
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
        s=func(s);
        t=func(t);
        return s==t;
    }
};