class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>v(query_row+1);
        v[0]={double(poured)};
        
        for(int i=1;i<query_row+1;i++){
            for(int j=0;j<i;j++){
                v[i].push_back((v[i-1][j]-min(1.0,v[i-1][j]))/2.0);
            }
            
            v[i].push_back((v[i-1].back()-min(1.0,v[i-1].back()))/2.0);

            for(int j=v[i].size()-2;j>=1;j--){
                v[i][j]+=(v[i-1][j-1]-min(v[i-1][j-1],1.0))/2.0;
            }

            
        }
        return min(1.0,v[query_row][query_glass]);
    }
};