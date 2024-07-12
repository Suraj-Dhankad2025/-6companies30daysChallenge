//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>>pq;
            
        vector<bool>isMST(V, 0);
        vector<int>parent(V); // to find the edges of MST if required
        int cost = 0;
        pq.push({0,{0, -1}});
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            if(!isMST[node]){
                isMST[node] = 1;
                cost+=wt;
                parent[node] = par;
                for(int j=0; j<adj[node].size(); j++){
                    int newNode = adj[node][j][0];
                    int newWeight = adj[node][j][1];
                    if(!isMST[newNode]){
                        pq.push({newWeight, {newNode, node}});
                    }
                }
            } 
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends