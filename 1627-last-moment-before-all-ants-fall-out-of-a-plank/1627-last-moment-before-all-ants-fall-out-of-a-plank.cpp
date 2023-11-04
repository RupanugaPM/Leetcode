#pragma GCC optimise("O3")
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        #pragma unroll
        for(auto i:left){
            ans=max(ans,i);
        }
        #pragma unroll
        for(auto i:right){
            ans=max(ans,n-i);
        }
        return ans;
    }
};