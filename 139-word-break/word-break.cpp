class Solution {
public:
    bool find(int i, string s, set<string>&st, vector<int>&dp){
        if(i>=s.size()){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        for(int j=i; j<s.size(); j++){
            if(st.find(s.substr(i,j-i+1))!=st.end()){
                if(find(j+1, s, st, dp)){
                    dp[i] = 1;
                    return 1;
                }
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(int i=0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
        vector<int>dp(s.size(),-1);
        return find(0, s, st, dp);
    }
};