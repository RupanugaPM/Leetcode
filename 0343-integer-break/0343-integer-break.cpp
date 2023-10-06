vector<int>dp(59,-1);

class Solution {
public:
    int integerBreak(int n) {
        if(dp[n]==-1){
            dp[1]=1;
            dp[2]=1;
            dp[3]=2;
            dp[4]=4;
            dp[5]=6;
            dp[6]=9;
            for(int i=6;i<59;i++){
                for(int j=1;j<i;j++){
                    dp[i]=max(dp[i],dp[j]*(i-j));
                }
            }
        }
        return dp[n];
    }
};