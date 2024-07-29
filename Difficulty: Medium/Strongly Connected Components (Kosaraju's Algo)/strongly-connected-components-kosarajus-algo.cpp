//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
	    vis[node] = 1;
	    for(auto j:adj[node]){
	        if(!vis[j]){
	            dfs(j, adj, vis);
	        }
	    }
	}
	void topo(int node, vector<vector<int>>&adj, stack<int>&st, vector<int>&vis){
	    vis[node] = 1;
	    for(auto j:adj[node]){
	        if(!vis[j]){
	            topo(j, adj, st, vis);
	        }
	    }
	    st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        vector<int>vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topo(i, adj, st, vis);
            }
        }
        vector<vector<int>> adj1(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                adj1[adj[i][j]].push_back(i);
            }
        }
        int ans = 0;
        fill(vis.begin(), vis.end(), 0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                ans++;
                dfs(node, adj1, vis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends