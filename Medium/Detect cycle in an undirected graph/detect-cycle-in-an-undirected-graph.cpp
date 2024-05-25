//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> adj[], vector<bool>&vis, int start){
        queue<pair<int, int>>q;
        vis[start] = 1;
        q.push({start, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto i:adj[node]){
                if(i==parent){
                    continue;
                }
                if(vis[i]){
                    return 1;
                }
                else{
                    vis[i] = 1;
                    q.push({i, node});
                }
            }
        }
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i] && bfs(adj, vis, i)){
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends