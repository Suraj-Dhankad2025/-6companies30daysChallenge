class Solution {
public:
    int find(int subtree, vector<vector<int>>&dist, int n){
        int nodes=0,edges=0,maxDis=0;
        for(int i=0; i<n; i++){
            if(((subtree>>i)&1)==0)continue;
            nodes++;
            for(int j=i+1; j<n; j++){
                if(((subtree>>j)&1)==0)continue;
                if(dist[i][j]==1){
                    edges++;
                }
                maxDis = max(maxDis, dist[i][j]);
            }
        }
        if(nodes == edges+1){
            return maxDis;
        }
        return 0;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int>d(n-1, 0);
        vector<vector<int>>dist(15, vector<int>(15, INT_MAX));
        for(auto i:edges){
            dist[i[0]-1][i[1]-1] = 1;
            dist[i[1]-1][i[0]-1] = 1;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)continue;
                    dist[i][j] = dist[j][i] = min({dist[i][j], dist[j][i], dist[i][k]+dist[k][j]}); 
                }
            }
        }
        for(int i=0; i<(1<<n); i++){
            int a = find(i, dist, n);
            if(a>0){
                d[a-1]++;
            }
        }
        return d;
    }
};