class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }
        vector<int>v1(n,0),v2(n,0),v3(n,0);
        v1[0]=0;
        v2[0]=-prices[0];
        v3[0]=INT_MIN;
        for(int i=1;i<n;i++){
            v1[i]=max(v1[i-1],v3[i-1]);
            v2[i]=max(v1[i-1]-prices[i],v2[i-1]);
            v3[i]=v2[i]+prices[i];
        }
        return max(v1.back(),v3.back());
    }
};