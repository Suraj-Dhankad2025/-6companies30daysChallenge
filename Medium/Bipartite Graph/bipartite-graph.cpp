//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int n, vector<int>adj[]){
	    queue<int>q;
        vector<int>color(n, -1);
        
        for(int i=0; i<n; i++){
            
            if(color[i]==-1){
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto i:adj[node]){
                        if(color[i]==-1){
                            color[i] = (1+color[node])%2;
                            q.push(i);
                        }
                        else if(color[i]==color[node]){
                            return 0;
                        }
                    }
                }
            }
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends