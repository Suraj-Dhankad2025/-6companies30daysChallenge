class Solution {
public:
    bool find(string &s, string &t){
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        if(j<=t.size()-1){
            return false;
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& d) {
        string ans="";
        int n = d.size();
        for(auto st:d){
            if(find(s, st)){
                if(st.size()>ans.size() || (st.size()==ans.size() && st<ans)){
                    ans = st;
                }
            }
        }
        return ans;
    }
};