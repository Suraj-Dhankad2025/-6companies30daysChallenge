class Solution {
public:
    vector<string>ans;
    void find(int i,string temp, string s, map<int, string>&m){
        if(i==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(auto it:m[s[i]-'0']){
            temp.push_back(it);
            find(i+1, temp, s, m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int, string>m;
        int n = digits.size();
        if(n==0)return {};
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        find(0, "", digits, m);
        return ans;
    }
};