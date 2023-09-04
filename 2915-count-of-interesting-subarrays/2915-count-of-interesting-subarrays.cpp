
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n=nums.size();
        vector<long long int>ps(n+1,0);
        unordered_map<long long int,long long int>mp;
        
        mp[0]++;
        for(int i=0;i<n;i++){
            ps[i+1]=(nums[i]%m==k)+ps[i];
            ps[i+1]%=m;
            mp[ps[i+1]]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            mp[ps[i]]--;
            int x=ps[i]+k;
            x%=m;
            ans+=mp[x];
        }
        return ans;
    }
};