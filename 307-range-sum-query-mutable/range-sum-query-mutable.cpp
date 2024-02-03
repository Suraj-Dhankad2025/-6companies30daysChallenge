class NumArray {
public:
    vector<int>arr;
    vector<int>tree;
    int n;

    void build(vector<int>&nums, int ind, int low, int high){
        if(low==high){
            tree[ind] = nums[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(nums, 2*ind + 1, low, mid);
        build(nums, 2*ind + 2, mid+1, high);

        tree[ind] = tree[2*ind + 1] + tree[2*ind + 2];
    }
    int makeUpdate(int ind, int low, int high, int target, int val){
        if(low==target && high==target){
            return tree[ind] = val;
        }
        if(low> target || high<target){
            return tree[ind];
        }
        int mid = low + (high - low)/2;
        int left = makeUpdate(2*ind+1,low,mid,target,val);
        int right = makeUpdate(2*ind+2,mid+1,high,target,val);
        tree[ind] = left + right;
        return tree[ind];
    }

    int find(int ind,int low,int high,int l,int r){

        if(low >= l && high <= r){
            return tree[ind];
        }

        if(low > r || high < l) return 0;

        int mid = low + (high - low) / 2;

        int left = find(2*ind+1,low,mid,l,r);
        int right = find(2*ind+2,mid+1,high,l,r);

        return left + right;
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n+1);
        build(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        makeUpdate(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return find(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */