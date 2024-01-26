class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = hBars.size();       
        int v = vBars.size();       
        int ans=0;
        int cnt=1;
        int hmax = 1;
        int vmax = 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for(int i=1; i<h; i++){
            if(hBars[i]==hBars[i-1] + 1){
                cnt++;
            }
            else cnt=1;
            hmax = max(hmax, cnt);
        }
        cnt = 1;
        for(int i=1; i<v; i++){
            if(vBars[i]==vBars[i-1] + 1){
                cnt++;
            }
            else cnt=1;
            vmax = max(vmax, cnt);
        }
        ans = min(hmax+1, vmax+1);
        return ans*ans;
    }
};