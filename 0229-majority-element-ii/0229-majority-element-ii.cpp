class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int lim=n/3;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto el:mp){
            if(el.second>lim){
                ans.push_back(el.first);
            }
        }
        return ans;
    }
};