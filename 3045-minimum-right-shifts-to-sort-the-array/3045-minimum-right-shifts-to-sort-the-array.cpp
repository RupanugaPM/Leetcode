class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int mi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<nums[mi]){
                mi=i;
            }
        }
        mi+=1;
        int t=1;
        for(int i=mi;i<mi+n-1;i++){
            if(nums[(i+n)%n]<nums[(i-1+n)%n]){
                t=0;
                break;
            }
        }
        if(t){
            return (n-(mi-1))%n;
        }
        return -1;
    }
};