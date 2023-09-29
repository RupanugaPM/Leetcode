vector<int>dp(10005,INT_MAX);
class Solution {
public:
    int numSquares(int n) {
        if(dp[n]<n){
            return dp[n];
        }
        precalc();
        return dp[n];
    }
    void precalc(){
        dp[0]=0;
        for(int i=0;i<10002;i++){
            int j=1;
            while(i+j*j<=10002){
                int x=i+j*j;
                dp[i+j*j]=min(dp[i+j*j],dp[i]+1);
                j++;
            }
        }
    }
};