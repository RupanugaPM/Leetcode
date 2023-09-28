class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>v1(n,0),v2(n,0);
        v1[0]=0;
        v2[0]=-prices[0]-fee;
        for(int i=1;i<n;i++){
            v2[i]=max(v2[i-1],v1[i-1]-prices[i]-fee);
            v1[i]=max(v1[i-1],v2[i-1]+prices[i]);
        }
        return v1.back();
    }
};