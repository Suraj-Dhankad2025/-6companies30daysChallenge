//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void dfs(int node, vector<int>adj[], vector<bool>&vis){
        vis[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                dfs(adj[node][i], adj, vis);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        vector<int>adj[26];
        vector<int>indeg(26, 0);
        vector<int>outdeg(26, 0);
        for(int i=0; i<N; i++){
            string s = A[i];
            int u = s[0]-'a';
            int v = s[s.length()-1]-'a';
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        //Eulerian circuit
        for(int i=0; i<26; i++){
            if(indeg[i]!=outdeg[i]){
                return 0;
            }
        }
        // All edges are part of single component
        // All the non zero degree node, they should be part of single component
        vector<bool>vis(26, 0);
        dfs(A[0][0]-'a', adj, vis);
        
        for(int i=0; i<26; i++){
            if(indeg[i] && !vis[i]){
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends