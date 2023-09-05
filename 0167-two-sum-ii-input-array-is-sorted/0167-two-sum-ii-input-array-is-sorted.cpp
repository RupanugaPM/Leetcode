class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(r>l){
            if(numbers[r]+numbers[l]>target){
                r--;
            }
            else if(numbers[r]+numbers[l]==target){
                return {l+1,r+1};
            }
            else{
                l++;
            }
        }
        return {-1,-1};
    }
};