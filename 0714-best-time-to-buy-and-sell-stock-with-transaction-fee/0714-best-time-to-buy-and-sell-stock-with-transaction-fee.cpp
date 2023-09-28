class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int v1,v2;
        v1=0;
        v2=-prices[0]-fee;
        int x;
        for(int i=1;i<n;i++){
            x=v2;
            v2=max(v2,v1-prices[i]-fee);
            v1=max(v1,x+prices[i]);
        }
        return v1;
    }
};