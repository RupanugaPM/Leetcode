#define bits(n) __builtin_popcount(n)
bool cmp(int &x1,int &x2){
    if(bits(x1)!=bits(x2)){
        return bits(x1)<bits(x2);
    }
    return x1<x2;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};