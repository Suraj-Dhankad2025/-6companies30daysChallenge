class Solution {
public:
    vector<int> lps(string &p){
        vector<int>ans(p.size(), 0);
        ans[0] = 0;
        int i=0,j=1;
        while(j<p.size()){
            if(p[i]==p[j]){
                ans[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i==0){
                    ans[j] = 0;
                    j++;
                }
                else{
                    i = ans[i-1];
                }
            }
        }
        return ans;
    }
    int KMP(string &s, string &p){
        vector<int>pre = lps(p);
        int i = 0;
        int j = 0;
        int N = s.size();
        int M = p.size();
        int ans=0;
        while(i<N){
            if(p[j] == s[i]){
                i++;
                j++;
            }
            if(j == M){
                ans++;
                j = pre[j-1];
            }else if(i < N && p[j] != s[i]){
                if(j != 0){
                    j = pre[j-1];
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pat) {
        string s="";
        string p="";
        for(int i=0; i<pat.size(); i++){
            if(pat[i]==1){
                p+='i';
            }
            else if(pat[i]==0){
                p+='e';
            }
            else{
                p+='d';
            }
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                s+='i';
            }
            else if(nums[i]<nums[i-1]){
                s+='d';
            }
            else{
                s+='e';
            }
        }
        int ans = KMP(s, p);
        return ans;
    }
};