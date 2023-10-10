class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        vector<int>ans(2);
        ans[0]=lower_bound(nums.begin(),nums.end(),tar)-nums.begin();
        ans[1]=upper_bound(nums.begin(),nums.end(),tar)-nums.begin();
        ans[1]-=1;
        if(ans[1]<0 || nums[ans[1]]!=tar){
            return {-1,-1};
        }
        return ans;
    }
};