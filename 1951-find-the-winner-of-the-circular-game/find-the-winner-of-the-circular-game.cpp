class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        int c = 0;
        int dost;
        while(q.size()>1){
            c=0;
            while(c<k-1){
                dost = q.front();
                q.pop();
                q.push(dost);
                c++;
            }
            q.pop();
        }
        return q.front();
    }
};