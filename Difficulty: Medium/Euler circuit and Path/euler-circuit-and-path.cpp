//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int node, vector<int>adj[], vector<bool>&vis){
        vis[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                dfs(adj[node][i], adj, vis);
            }
        }
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    //Euler Path :1
	    // Calculate the degree of each node
	    // zero or two node can have odd degree and remaining have even degree
	    // All non-zero degree nodes should be connected
	    
	    //Euler Circuit :2
	    // Calculate the degree of each node
	    // All nodes should have even degree
	    // All non-zero degree nodes should be connected
	    vector<int>deg(V, 0);
	    int oddDeg = 0;
	    for(int i=0; i<V; i++){
	        deg[i] = adj[i].size();
	        if(deg[i]%2==1){
	            oddDeg++;
	        }
	    }
	    if(oddDeg!=0 && oddDeg!=2){
	        return 0;
	    }
	    vector<bool>vis(V, 0);
	    for(int i=0; i<V; i++){
	        if(deg[i]){
	            dfs(i, adj, vis);
	            break;
	        }
	    }
	    // If non zero degree node is still not visited, return 0
	    // Degree zero hai, usko ignore(koi edge nhi hai)
	    for(int i=0; i<V; i++){
	        if(deg[i] && !vis[i]){
	            return 0;
	        }
	    }
	    if(oddDeg==0){
	        return 2;
	    }
	    return 1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends