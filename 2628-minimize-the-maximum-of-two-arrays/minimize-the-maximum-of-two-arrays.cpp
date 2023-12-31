class Solution {
public:
    int minimizeSet(int d1, int d2, int uc1, int uc2) {
        long long s=1,e=INT_MAX;
        long long lcm = (long long)d1*d2/gcd(d1, d2);
        int ans=1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int notd1 = mid - mid/d1;
            int notd2 = mid - mid/d2;
            int notBoth = mid - mid/lcm;
            if(notd1>=uc1 && notd2>=uc2 && notBoth>=(uc1+uc2)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};