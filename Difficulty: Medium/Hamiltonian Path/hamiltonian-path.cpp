//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, int count, int N) {
        vis[node] = 1;
        count++;
        if (count == N) {
            return 1;
        }
        for (auto i : adj[node]) {
            if (!vis[i] && dfs(i, adj, vis, count, N)) {
                return 1;
            }
        }
        vis[node] = 0; 
        return 0;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> adj[N];
        for (int i = 0; i < M; i++) {
            adj[Edges[i][0]-1].push_back(Edges[i][1]-1);
            adj[Edges[i][1]-1].push_back(Edges[i][0]-1);
        }
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++) {
            if (!vis[i] && dfs(i, adj, vis, 0, N)) {
                return 1;
            }
        }
        return 0;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends