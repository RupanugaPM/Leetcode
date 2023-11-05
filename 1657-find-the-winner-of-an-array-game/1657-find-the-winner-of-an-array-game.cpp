class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            v.push_back(arr[i]);
        }
        int x,y;
        map<int,int>mp;
        int ans=-1;
        for(int i=0;i<n;i++){
            x=max(v[0],v[1]);
            y=min(v[0],v[1]);
            mp[x]++;
            v.pop_front();
            v.push_back(y);
            v[0]=x;
            if(mp[x]==k){
                ans=x;
                break;
            }
        }
        if(ans==-1){
            return v[0];
        }
        return ans;
    }
};