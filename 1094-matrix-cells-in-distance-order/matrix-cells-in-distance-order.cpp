class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
         vector<vector<int>>ans;
        priority_queue<pair<int, pair<int, int>>>pq;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int dis = abs(rCenter - i) + abs(cCenter - j);
                pq.push({-dis,{i,j}});
            }
        }
        while(!pq.empty()){
            auto [i,j] = pq.top().second;
            pq.pop();
            ans.push_back({i,j});
        }
        return ans;
    }
};