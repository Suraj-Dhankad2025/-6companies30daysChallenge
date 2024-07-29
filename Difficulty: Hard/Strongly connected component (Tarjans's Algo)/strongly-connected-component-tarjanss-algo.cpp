//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    void dfs(int node, vector<int>adj[], vector<int>&dis, vector<int>&low, vector<bool>&vis, 
            stack<int>&st, vector<bool>&InStack, int &timer, vector<vector<int>>&ans){
        vis[node] = 1;
        dis[node] = low[node] = timer;
        timer++;
        InStack[node] = 1;
        st.push(node);
        
        for(int j=0; j<adj[node].size(); j++){
            int neigh = adj[node][j];
            if(!vis[neigh]){
                dfs(neigh, adj, dis, low, vis, st, InStack, timer, ans);
                low[node] = min(low[node], low[neigh]);
            }
            else{
                if(InStack[neigh]){
                    low[node] = min(low[node], dis[neigh]);
                }
            }
        }
        if(dis[node]==low[node]){
            vector<int>temp;
            while(!st.empty() && st.top()!=node){
                temp.push_back(st.top());
                InStack[st.top()] = 0;
                st.pop();
            }
            temp.push_back(node);
            InStack[node] = 0;
            st.pop();
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>>ans;
        vector<int>dis(V, 0);
        vector<int>low(V, 0);
        vector<bool>vis(V, 0);
        stack<int>st;
        vector<bool>InStack(V, 0);
        int timer = 0;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, dis, low, vis, st, InStack, timer, ans);
            }
        }
        sort(ans.begin(), ans.end());
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

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends