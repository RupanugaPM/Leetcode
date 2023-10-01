class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int a=~(0);
        for(int i=0;i<nums.size();i++){
            a&=nums[i];
        }
        if(a>0){
            return 1;
        }
        int k=~(0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            k&=nums[i];
            if(k==a){
                k=~(0);
                ans++;
            }
        }
        return ans;
    }
};