class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        vector<long long int>v(n,0);
        for(int i=0;i<=30;i++){
            for(int j=0;j<n;j++){
                mp[1<<i]+=((nums[j]&(1<<i))!=0);
            }
            for(int j=0;j<n;j++){
                if(mp[1<<i]>0){
                    mp[1<<i]--;
                    v[j]+=(1<<i);
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<k;i++){
            ans+=v[i]*v[i];
            ans%=1000000007;
        }
        return ans;
    }
};