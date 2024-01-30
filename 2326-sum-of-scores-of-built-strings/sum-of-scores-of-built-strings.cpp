class Solution {
public:
    vector<int> find(string &s){
        int i=0,j=1;
        vector<int>lps(s.size(), 0);
        lps[0] = 0;
        while(j<s.size()){
            if(s[i]==s[j]){
                lps[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i==0){
                    lps[j] = 0;
                    j++;
                }
                else{
                    i = lps[i-1];
                }
            }
        }
        return lps;
    }
    long long sumScores(string s) {
        vector<int> cnt;
        vector<int>lps = find(s);
        for (int j :  lps)
            cnt.push_back(j == 0 ? 0 : cnt[j - 1] + 1);   
        return accumulate(begin(cnt), end(cnt), 0LL) + s.size();
    }
};