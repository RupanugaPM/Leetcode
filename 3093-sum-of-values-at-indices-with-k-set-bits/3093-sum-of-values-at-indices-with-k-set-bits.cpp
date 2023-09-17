#define bits(n) __builtin_popcount(n)
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(bits(i)==k){
                ans+=nums[i];
            }
        }
        return ans;
    }
};