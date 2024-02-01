class Solution {
public:
    map<int,map<vector<int>,int>> dp;
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> &needs, int i, vector<int>ds){
        if(i==special.size()){
            int res = 0;
            for(int k=0;k<needs.size();k++){
                res += (needs[k] - ds[k]) * price[k];
            }
            return res;
        }
        if(dp.find(i)!=dp.end() && dp[i].find(ds)!=dp[i].end()){
            return dp[i][ds];
        }
        int notTake = solve(price, special, needs, i + 1, ds);
        vector<int>v = ds;

        for(int j=0;j<needs.size();j++){
            if(v[j]+special[i][j]<=needs[j]){
                v[j] = v[j] + special[i][j]; 
            }
            else{
                return dp[i][ds] = notTake;
            } 
        }
        int take = special[i][price.size()] + solve(price, special, needs, i, v);
        return dp[i][ds] = min(take, notTake);
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector<int>ds(needs.size(), 0);
        return solve(price, special, needs, 0, ds);
    }
};