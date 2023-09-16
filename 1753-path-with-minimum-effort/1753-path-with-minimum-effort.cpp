# define INF 1e9
class Solution {
public:
    bool is_valid(int x, int y, int n, int m){
        if(x>=0 && y>=0 && x<n && y<m){
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        long long m = heights[0].size();
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> efforts(heights.size(), vector<int>(heights[0].size(), INF));
        st.insert({0, {0, 0}});
        efforts[0][0] = 0;

        int Dir[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};

        while(!st.empty()){
            // Find the top one
            pair<int, int> node = (*st.begin()).second;
            long long effort = (*st.begin()).first;
            st.erase(st.begin());
            // Find neighbours
            for(int i = 0; i < 4; i++){
                pair<int, int> neighbour = {node.first + Dir[0][i], node.second + Dir[1][i]};
                // If the neighbour has been visited and effort is less
                if(is_valid(neighbour.first, neighbour.second, n, m)){
                    long long new_effort = max(efforts[node.first][node.second], abs(heights[neighbour.first][neighbour.second]- heights[node.first][node.second]));
                    if(new_effort < efforts[neighbour.first][neighbour.second]){
                        st.erase({efforts[neighbour.first][neighbour.second], neighbour});
                        efforts[neighbour.first][neighbour.second] = new_effort;
                        st.insert({efforts[neighbour.first][neighbour.second], neighbour});
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }
};