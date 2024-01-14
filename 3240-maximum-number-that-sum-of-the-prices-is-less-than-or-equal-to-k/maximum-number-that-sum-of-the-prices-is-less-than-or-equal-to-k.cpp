class Solution {
public:
    long long find(long long mid, int x){
        long long sum=0;
        for(long long i=x-1;i<=60;i+=x){
            long long dividend=mid+1;
            long long patsize=(1LL<<(i+1));
            sum+=patsize/2*(dividend/patsize);
            long long rem=dividend%patsize;
            if(rem<=patsize/2) continue;
            rem%=(patsize/2);
            sum+=rem;
        }
        return sum;
    }
    long long findMaximumNumber(long long k, int x) {
        long long ans=1;
        long long start = 1;
        long long end = 1e15-1;
        while(start<=end){
            long long mid = start + (end-start)/2;
            long long sum = find(mid,x);
            if(sum>k){
                end = mid-1;
            }
            else{
                ans = max(ans, mid);
                start = mid+1;
            }
        }
        return ans;
    }
   
};