class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>ans(m, vector<int>(n, 0));
        vector<vector<int>>vis(m, vector<int>(n, 0));
        queue<pair<int, int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]==1){
                    vis[i][j]=1;
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    if(isWater[nr][nc]==0){
                        ans[nr][nc] = 1 + ans[i][j];
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        return ans;
    }
};