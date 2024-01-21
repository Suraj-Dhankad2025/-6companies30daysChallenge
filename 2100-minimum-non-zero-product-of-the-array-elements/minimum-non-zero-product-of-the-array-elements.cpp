class Solution {
public:
     int mod = 1e9 + 7;
    long long find(long long base, long long exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base % mod;
        long long tmp = find(base, exponent/2);
        if (exponent % 2 == 0) { 
            return (tmp * tmp) % mod;
        }
        else { 
            tmp = tmp * tmp % mod;
            base %= mod;
            return (tmp * base) % mod;
        }
    }
    int minNonZeroProduct(int p) {
        long long ans=1;
        long long val = pow(2, p);
        val--;
        long long exp = find(val-1,val/2)%mod;
        ans = (exp*(val%mod))%mod;
        return ans%mod;
    }
};