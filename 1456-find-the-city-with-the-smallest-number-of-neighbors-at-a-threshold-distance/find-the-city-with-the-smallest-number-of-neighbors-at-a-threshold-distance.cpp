class Solution {
public:
    int find(int n,int ind, vector<pair<int, int>>adj[], int td){
        vector<int>dist(n,1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        q.push({0,ind});
        int ans = 0;
        dist[ind] = 0;
        while(!q.empty()){
            auto [dis, node] = q.top();
            q.pop();
            for(auto [newNode, d]:adj[node]){
                if(d + dis <= dist[newNode]){
                    dist[newNode] = d + dis;
                    q.push({d+dis,newNode});
                }
            }
        }
        for(auto i:dist){
            if(i<=td)ans++;
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& e, int distanceThreshold) {
        vector<pair<int, int>>adj[n];
        for(int i=0; i<e.size(); i++){
            adj[e[i][0]].push_back({e[i][1], e[i][2]});
            adj[e[i][1]].push_back({e[i][0], e[i][2]});
        }
        int cnt = INT_MAX;
        int ans=0;
        for(int i=0; i<n; i++){
            int c = find(n,i, adj, distanceThreshold);
            if(c<=cnt){
                cnt = c;
                ans=i;
            }
        }
        return ans;
    }
};