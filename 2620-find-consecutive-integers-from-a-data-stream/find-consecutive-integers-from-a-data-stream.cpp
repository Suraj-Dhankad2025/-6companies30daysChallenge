class DataStream {
public:
    int val;
    int K;
    int cnt;
    DataStream(int value, int k) {
        this->cnt = 0;
        this->K = k;
        this->val = value;
    }
    
    bool consec(int num) {
        if(val==num){
            cnt++;
        }
        else{
            cnt = 0;
        }
        return cnt>=K;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */