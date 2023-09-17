class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int mx=0;
        for(auto el:mp){
            mx=max(mx,el.second);
        }
        if(mx>n/2){
            return 2*mx-n;
        }
        return n%2;
    }
};