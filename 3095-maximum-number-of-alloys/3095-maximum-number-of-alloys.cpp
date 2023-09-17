class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& c, vector<int>& stock, vector<int>& cost) {
        int ans=0;
        for(int i=0;i<k;i++){
            int l=0;
            int r=1e9;
            while(l<=r){
                long long  mid=(l+r)/2;
                long long inc=0;
                for(int j=0;j<n;j++){
                    if(stock[j]>mid*c[i][j]){
                    
                    }
                    else{
                        inc+=cost[j]*(mid*c[i][j]-stock[j]);
                    }
                }
                if(inc<=budget){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            ans=max(ans,r);
        }
        return ans;
    }
};