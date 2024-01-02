class Solution {
public:
    vector<string>ans;
    void find(int i,string temp, string s, vector<string>&v){
        if(i==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(auto it:v[s[i]-'0'-2]){
            temp.push_back(it);
            find(i+1, temp, s, v);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>v(8);
        int n = digits.size();
        if(n==0)return {};
        v[0] = "abc";
        v[1] = "def";
        v[2] = "ghi";
        v[3] = "jkl";
        v[4] = "mno";
        v[5] = "pqrs";
        v[6] = "tuv";
        v[7] = "wxyz";
        find(0, "", digits, v);
        return ans;
    }
};