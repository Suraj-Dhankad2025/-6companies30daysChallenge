class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i=0,j=0;
        int ans = 0;
        while(j<n){
            if(s[j]==t[j]){
                ans = max(ans, j-i+1);
                j++;
                continue;
            }
            maxCost = maxCost - abs(s[j]-t[j]);
            while(maxCost<0 && i<j){
                maxCost = maxCost + abs(s[i]-t[i]);
                i++;
            }
            if(maxCost>=0)ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};