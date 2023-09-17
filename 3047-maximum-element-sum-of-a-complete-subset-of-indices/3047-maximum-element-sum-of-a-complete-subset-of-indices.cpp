vector<int> sv(10005);
void sieve()
{
    //seive of eratosthanos
    sv[1] = 1;
    int n=sv.size();
    for (int i=2; i<n-1; i++)
        sv[i] = i;
    for (int i=4; i<n-1; i+=2)
        sv[i] = 2;

    for (int i=3; i*i<n-1; i++)
    {
        if (sv[i] == i)
        {
            for (int j=i*i; j<n-1; j+=i)
                if (sv[j]==j)
                    sv[j] = i;
        }
    }
}

class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        sieve();
        int n=nums.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            int x=i+1;
            int eq=1;
            while(x!=1){
                int y=sv[x];
                int c=0;
                while(x!=1 && x%y==0){
                    x/=y;
                    c++;
                }
                if(c%2==1){
                    eq*=y;
                }
            }
            mp[eq].push_back(nums[i]);
        }
        long long ans=0;
        for(auto el:mp){
            long long ansl=0;
            for(auto e:el.second){
                ansl+=e;
            }
            ans=max(ans,ansl);
        }
        return ans;
    }
};