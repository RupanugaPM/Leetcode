class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>v(101,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<101;i++){
            ans+=v[i]*(v[i]-1)/2;
        }
        return ans;
    }
};