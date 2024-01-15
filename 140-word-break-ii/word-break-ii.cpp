class Solution {
public:
    vector<string>a;
    void find(int i, string temp, string &s, set<string>&st, vector<string>&ans){
        if(i>=s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return ;
        }
        for(int j=i; j<s.size(); j++){
            if(st.find(s.substr(i, j-i+1))!=st.end()){
                find(j+1, temp+s.substr(i, j-i+1)+" ", s, st, ans);
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        set<string>st;
        for(auto i:wordDict){
            st.insert(i);
        }
        find(0, "", s, st, ans);
        return ans;
    }
};