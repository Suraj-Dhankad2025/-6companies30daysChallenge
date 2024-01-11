class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        vector<pair<int, int>>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int>totalTime(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        totalTime[0] = 0;
        pq.push({fees[0],{0,0}});
        while(!pq.empty()){
            auto [city, time] = pq.top().second;
            int fee = pq.top().first;
            pq.pop();
            if(city==n-1)return fee;
            for(auto [newCity,t]:adj[city]){
                if (time + t > maxTime || totalTime[newCity]<=time + t) {
                    continue;
                }
                totalTime[newCity] = time + t;
                pq.push({fee+fees[newCity], {newCity, time + t}});
            } 
        }
        return -1;
    }
};