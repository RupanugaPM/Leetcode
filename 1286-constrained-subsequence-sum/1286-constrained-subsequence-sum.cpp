class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        multiset<int>ms;
        int n=nums.size();
        ms.insert(0);
        int l=0;
        int mx;
        int ans=-1e9;
        for(int i=0;i<n;i++){
            mx=*ms.rbegin();
            mx+=nums[i];
            ans=max(ans,mx);
            ms.insert(mx);
            nums[i]=mx;
            if(i-l==k){
                ms.erase(ms.find(nums[l]));
                l++;
            }
        }
        return ans;
    }
};