class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int>dp(target+1,0);
        dp[0]=1;
        long long int m=1e10;
        for(int i=1;i<target+1;i++){
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j])
                    dp[i]+=dp[i-nums[j]];
                dp[i]%=m;
            }
        }
        return dp.back();
    }
};