class Solution {
public:
    int dp[11][2][2][21][10][10];
    int solve(int ind,const string &s,bool tight,bool isMake,int rem,int odd,int even,int k)
    {
        if(ind==s.size()) {
            return (even>0||odd>0) &&(even==odd && rem==0);
        }
       if(dp[ind][tight][isMake][rem][odd][even]!=-1) return dp[ind][tight][isMake][rem][odd][even];
        int high = (tight==true)?s[ind]-'0':9;
        int ans = 0;
        for(int i=0;i<=high;i++)
        {
            int new_rem = (rem*10+i)%k;
            int new_odd = odd;
            int new_even= even;
            if(i==0&&isMake==false){}
            else
            {
                if(i%2) new_odd+=1;
                else new_even+=1;
            }
            ans+=solve(ind+1,s,tight&(i==high),isMake|i>0,new_rem,new_odd,new_even,k);
        }
        return dp[ind][tight][isMake][rem][odd][even] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp,-1,sizeof(dp));
        int ans1 = solve(0,to_string(high),1,0,0,0,0,k);
        memset(dp,-1,sizeof(dp));
        int ans2 = solve(0,to_string(low-1),1,0,0,0,0,k);
        return ans1-ans2;
    }
};