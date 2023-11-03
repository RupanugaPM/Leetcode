class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        int j=0;
        int c=0;
        vector<string>ans;
        for(int i=1;i<=n;i++){
            if(t[j]==i){
                while(c){
                    ans.push_back("Pop");
                    c--;
                }
                ans.push_back("Push");
                j++;
                if(j>=t.size()){
                    break;
                }
            }
            else if(t[j]>i){
                ans.push_back("Push");
                c++;
            }
        }
        return ans;
    }
};