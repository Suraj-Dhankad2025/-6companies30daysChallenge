class Solution {
public:
    vector<int> findLPS(string &s){
        vector<int>lps(s.size(),0);
        int pre = 0;
        int suf = 1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf] = pre+1;
                suf++;
                pre++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        return lps;
    }
    vector<int> kmp(string s, string pat){
        vector<int>lps = findLPS(pat);
        int i=0, j=0;
        vector<int>a;
        while(i<s.size()){
            if(s[i]==pat[j]){
                i++;
                j++;
            }
            if(j==pat.size()){
                a.push_back(i-j);
                j=lps[j-1];
            }
            else if(s[i]!=pat[j]){
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return a;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ind_i = kmp(s,a);
        vector<int>ind_j = kmp(s,b);
        vector<int>ans;
        for(int i=0; i<ind_i.size(); i++){
            int ind=ind_i[i];
            int j = lower_bound(ind_j.begin(), ind_j.end(), ind-k) - ind_j.begin();
            if(j==ind_j.size())break;
            if(abs(ind-ind_j[j])<=k){
                ans.push_back(ind);
            }
        }
        return ans;
    }
};