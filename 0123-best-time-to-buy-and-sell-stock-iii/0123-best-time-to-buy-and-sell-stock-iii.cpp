class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>pre(n,0),sux(n,0);
        
        pre[0]=0;
        int mi=prices[0];
        for(int i=1;i<n;i++){
            pre[i]=max(prices[i]-mi,pre[i-1]);
            mi=min(prices[i],mi);
        }
        sux[n-1]=0;
        int ma=prices[n-1];
        for(int i=n-2;i>=0;i--){
            sux[i]=max(sux[i+1],ma-prices[i]);
            ma=max(ma,prices[i]);
        }
        int ans=0;
        for(int i=0;i<n-2;i++){
            ans=max(ans,pre[i]+sux[i+1]);
        }
        return max(ans,pre[n-1]);
    }
};