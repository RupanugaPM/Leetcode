class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool t1=true,t2=true;
        for(int i=0;i<nums.size()-1;i++){
            t1&=(nums[i]<=nums[i+1]);
            t2&=(nums[i]>=nums[i+1]);
        }
        return t1|t2;
    }
};