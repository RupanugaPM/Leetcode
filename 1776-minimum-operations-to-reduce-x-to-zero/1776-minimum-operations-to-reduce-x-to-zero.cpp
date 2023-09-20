class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int>mp;
        int n=nums.size();
        vector<int>suf(n,0);
        suf[n-1]=nums[n-1];
        mp[suf[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i];
            mp[suf[i]]=n-i;
        }
        int pre=0;
        int ans=nums.size()+1;
        if(mp.find(x)!=mp.end()){
            ans=min(ans,mp[x]);
        }
        for(int i=0;i<n;i++){
            pre+=nums[i];
            mp.erase(nums[i]);
            if(x-pre==0){
                ans=min(ans,i+1);
            }
            if(mp.find(x-pre)!=mp.end()){
                ans=min(ans,i+1+mp[x-pre]);
            }
        }
        if(ans==n+1){
            return -1;
        }
        return ans;
    }
};