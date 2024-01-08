class Solution {
public:
    vector<vector<int>>rect;
    Solution(vector<vector<int>>& rects) {
        this->rect = rects;
    }
    vector<int> pick() {
        int totalArea=0;
        vector<int>r;
        for(auto i:rect){
            int area = (i[3]-i[1]+1)*(i[2]-i[0]+1);
            totalArea += area;
            if(rand()%totalArea<area){
                r = i;
            }
        }
        int x = rand()%(r[2]-r[0]+1) + r[0];
        int y = rand()%(r[3]-r[1]+1) + r[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */