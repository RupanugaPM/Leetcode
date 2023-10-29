#pragma GCC optimize("O3")
class Solution {
public:
    int poorPigs(int b, int md, int mt) {
        int x=0, B=mt/md+1, P=1;
        for(;P<b;x++) P*=B;
        return x;
    }
};