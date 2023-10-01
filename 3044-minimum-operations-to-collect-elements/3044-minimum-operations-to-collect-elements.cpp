class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;
        int ans=0;
        int cur=1;
        for(int i=nums.size()-1;i>=0;i--){
            s.insert(nums[i]);
            while(cur<k+1 && s.find(cur)!=s.end()){
                cur++;
            }
            ans++;
            if(cur==k+1){
                break;
            }
        }
        return ans;
    }
};