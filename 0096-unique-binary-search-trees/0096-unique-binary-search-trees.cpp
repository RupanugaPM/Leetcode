vector<int>dp(20,-1);
class Solution {
public:
    int numTrees(int n) {
        if(n==1 || n==0){
            return dp[n]=1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=0;
        for(int i=0;i<=n-1;i++){
            dp[n]+=numTrees(i)*numTrees(n-1-i);
        }
        return dp[n];
    }
};