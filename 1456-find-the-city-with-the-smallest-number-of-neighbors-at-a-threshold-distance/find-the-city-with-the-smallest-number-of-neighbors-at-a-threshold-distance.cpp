class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        int e = edges.size();
        vector<pair<int, int>>adj[n];
        for(int i=0; i<e; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        int ans = -1;
        int num=INT_MAX;
        for(int i=0; i<n; i++){
            vector<int>dist(n, 1e9);
            int c=0;
            dist[i] = 0;
            pq.push({0, i});
            while(!pq.empty()){
                auto [dis, city] = pq.top();
                pq.pop();
                for(auto [newCity, d]:adj[city]){
                    if(d+dis<dist[newCity]){
                        dist[newCity] = d + dis;
                        pq.push({d + dis, newCity});
                    }
                }
            }
            for(int i=0; i<n; i++){
                if(dist[i]<=th){
                    c++;
                }
            }
            if(c<=num){
                num = c;
                ans = i;
            }
        }
        return ans;
    }
};