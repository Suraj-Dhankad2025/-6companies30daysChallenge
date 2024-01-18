class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 0;
        while(x>0 && y>0){
            ans+=4;
            x--;
            y--;
        }
        if(x>=1){
            ans+=2;
        }
        if(y>=1){
            ans+=2;
        }
        ans+=z*2;
        return ans;
    }
};