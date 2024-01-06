class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int c=0;
        int sum=0;
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>>ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum=0;
                c=0;
                for(int k=-1; k<=1; k++){
                    for(int l=-1; l<=1; l++){
                        int nr = i + k;
                        int nc = j + l;
                        if(nr<m && nc<n && nr>=0 && nc>=0){
                            sum+=img[nr][nc];
                            c++;
                        }
                    }
                }
                if(sum==0 || c==0){
                    continue;
                }
                ans[i][j] = sum/c;
            }
        }
        return ans;
    }
};