class Solution {
public:
    int countOrders(int n) {
        long long int ans=1;
        for(int i=2;i<=n;i++){
            ans*=i*(2*i-1);
            ans%=int(1e9+7);
        }
        return ans;
    }
};