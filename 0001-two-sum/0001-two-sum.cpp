class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v(nums.size());
        for(int i=0;i<nums.size();i++){
            v[i]={nums[i],i};
        }
        sort(v.begin(),v.end());
        int l=0,r=nums.size()-1;
        vector<int> ans={-1,-1};
        while(l<r){
            if(v[l].first+v[r].first>target){
                r--;
            }
            else if(v[l].first+v[r].first==target){
                ans={v[l].second,v[r].second};
                break;
            }
            else{
                l++;
            }
        }
        
        return ans;
    }
};