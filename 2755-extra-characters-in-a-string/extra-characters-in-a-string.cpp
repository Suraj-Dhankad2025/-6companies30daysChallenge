class Solution {
public:
    int find(int i,set<string>&st, string &s, vector<int>&dp){
        if(i>=s.size()){
           return 0;
        }
        if(dp[i]!=-1)return dp[i];
        string str="";
        int n = s.size();
        for(int j=i; j<s.size(); j++){
            str+=s[j];
            int c = str.size();
            if(st.find(str)!=st.end()){
                c=0;
            }
            n = min(n, c+find(j+1, st,s, dp));
        }
        return dp[i] = n;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string>st;
        for(auto i:dictionary){
            st.insert(i);
        }
        vector<int>dp(s.size(), -1);
        return find(0, st,s, dp);
    }
};