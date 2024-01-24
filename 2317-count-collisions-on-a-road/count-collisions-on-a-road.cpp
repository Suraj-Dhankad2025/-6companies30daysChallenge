class Solution {
public:
    int countCollisions(string dir) {
        int ans=0;
        int n = dir.size();
        int l=0,r=n-1;

        while(r>=0 && dir[r]=='R')
            r--;
        
        while(l<n && dir[l]=='L')
            l++;
        
        for(int i=l; i<=r; i++)
            if(dir[i]!='S')ans++;
        
        return ans;
    }
};