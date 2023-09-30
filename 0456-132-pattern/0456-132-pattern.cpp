class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int,int>right;
        int n=nums.size();
        int mi=nums[0];
        for(int i=1;i<n;i++){
            right[nums[i]]++;
        }
        bool ans=false;
        for(int i=1;i<n-1;i++){
            right[nums[i]]--;
            if(right[nums[i]]==0){
                right.erase(nums[i]);
            }
            int y=right.upper_bound(mi)->first;
            if(y<nums[i] && y>mi && right.find(y)!=right.end()){
                ans=true;
                break;
            }
            mi=min(mi,nums[i]);
        }
        return ans;
    }
};