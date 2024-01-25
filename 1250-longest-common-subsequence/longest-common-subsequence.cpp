class Solution {
public:
    int find(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i>=s.size() || j>=t.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            ans = 1 + find(i+1, j+1, s, t, dp);
        }
        else{
            ans = max(find(i+1, j, s, t, dp), find(i, j+1, s, t, dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return find(0, 0, text1, text2, dp);
    }
};