//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>vis(V, 0);
        vector<int>dis(V, INT_MAX);
        dis[S] = 0;
        int count = V;
        while(count--){
            // Select a node which is not explored yet and its distance is minimum
            int val = INT_MAX;
            int node = -1;
            for(int i=0; i<V; i++){
                if(!vis[i] && val>dis[i]){
                    node = i;
                    val = dis[i];
                }
            }
            vis[node] = 1;
            // Relax the Edges
            for(int j=0; j<adj[node].size(); j++){
                int neighbour = adj[node][j][0];
                int weight = adj[node][j][1];
                if(!vis[neighbour] && dis[node]+weight<dis[neighbour]){
                     dis[neighbour] = dis[node] + weight;
                }
            }
        }
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends