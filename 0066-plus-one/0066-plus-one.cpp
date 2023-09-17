class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        digits[n-1]+=1;
        int c=(digits[n-1])/10;
        digits[n-1]%=10;
        n-=2;
        while(n>=0 && c){
            digits[n]+=c;
            c=digits[n]/10;
            digits[n]%=10;
            n-=1;
        }
        if(c){
            digits.insert(digits.begin(),c);
        }
        return digits;
    }
};