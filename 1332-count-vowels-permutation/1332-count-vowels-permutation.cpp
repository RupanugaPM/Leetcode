class Solution {
public:
    int countVowelPermutation(int n) {
        vector<array<long long int,5>>v(n);
        v[0][0]=1;
        v[0][1]=1;
        v[0][2]=1;
        v[0][3]=1;
        v[0][4]=1;
        long long int mod=1e9;
        mod+=7;
        for(int i=1;i<n;i++){
            v[i][0]=v[i-1][1]+v[i-1][2]+v[i-1][4];
            v[i][1]=v[i-1][0]+v[i-1][2];
            v[i][2]=v[i-1][3]+v[i-1][1];
            v[i][3]=v[i-1][2];
            v[i][4]=v[i-1][2]+v[i-1][3];
            v[i][0]%=mod;
            v[i][1]%=mod;
            v[i][2]%=mod;
            v[i][3]%=mod;
            v[i][4]%=mod;
        }
        return (v[n-1][0]+v[n-1][1]+v[n-1][2]+v[n-1][3]+v[n-1][4])%mod;
    }
};