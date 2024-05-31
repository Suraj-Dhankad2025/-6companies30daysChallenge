//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void findTopo(int node, vector<pair<int, int>> adj[], stack<int>& s, vector<int>& vis) {
    vis[node] = 1;
    for(auto i : adj[node]) {
        if(!vis[i.first]) {
            findTopo(i.first, adj, s, vis);
        }
    }
    s.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[N];
    for(int i = 0; i < M; i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    stack<int> s;
    vector<int> vis(N, 0);

    // Assuming the graph is connected and we can start the topological sort from node 0
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            findTopo(i, adj, s, vis);
        }
    }

    vector<int> dis(N, INT_MAX);
    dis[0] = 0;

    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if (dis[node] != INT_MAX) {
            for(auto i : adj[node]) {
                if(dis[i.first] > dis[node] + i.second) {
                    dis[i.first] = dis[node] + i.second;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(dis[i] == INT_MAX) {
            dis[i] = -1;
        }
    }

    return dis;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends