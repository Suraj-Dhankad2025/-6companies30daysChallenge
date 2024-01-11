class Solution {
public:
    int find(vector<pair<int, int>>adj[], int s, int t){
        queue<pair<int, int>>q;
        q.push({0,s});
        vector<long long>cost(26,LONG_MAX);
        cost[s] = 0;
        long long ans=LONG_MAX;
        while(!q.empty()){
            int c = q.front().first;
            int ch = q.front().second;
            q.pop();
            for(auto it:adj[ch]){
                int newCh = it.first;
                int newCost = it.second;
                if(newCost+c<cost[newCh]){
                    q.push({newCost+c, newCh});
                    cost[newCh] = newCost + c;
                    if(newCh==t){
                        ans = newCost + c;
                    }
                }
            }
        }
        return (ans==LONG_MAX)? -1:ans;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int, int>>adj[26];
        for(int i=0; i<original.size(); i++){
            adj[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
        }
        int n = source.size();
        long long ans = 0;
        unordered_map<long long, long long>mp;
        for(int i=0; i<n; i++){
            if(source[i]!=target[i]){
                long long temp = -1;
                long long hash = (source[i]-'a')*100 + target[i] - 'a';
                if(mp.find(hash)!=mp.end()){
                    temp = mp[hash];
                }
                else{
                    temp = find(adj, source[i]-'a', target[i]-'a');
                    mp[hash] = temp;
                }
                if(temp==-1){
                    return -1;
                }
                ans+=temp;
            }
        }
        return ans;
    }
};