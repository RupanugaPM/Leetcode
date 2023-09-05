using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    dp[i][j]=(p[j-1]=='*'&&dp[i][j-2]);
                }
                else if(j==0){
                    dp[i][j]=false;
                }
                else{
                    if(p[j-1]=='*'){
                        dp[i][j]=(dp[i][j-2])|(dp[i-1][j]& (s[i-1]==p[j-2] | p[j-2]=='.'));
                    }
                    else{
                        dp[i][j]=(dp[i-1][j-1]& (s[i-1]==p[j-1] | p[j-1]=='.'));

                    } 
                }
            }
        }
        return dp[n][m];
    }
};
