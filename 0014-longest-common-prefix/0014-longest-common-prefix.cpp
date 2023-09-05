class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp=strs[0];
        for(int i=1;i<strs.size();i++){
            string s;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]==lcp[j]){
                    s+=lcp[j];
                }
                else{
                    break;
                }
            }
            lcp=s;
        }
        return lcp;
    }
};