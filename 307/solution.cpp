#define lowbit(x) ((x) & -(x))
/*this solution is very good!*/
class NumArray {
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        this->length = n;
        this->tree = new int[n*2];
        
        for(int i = 0;i < n; ++i){
            tree[n+i] = nums[i]; 
        }
        for(int i = n-1;i > 0; --i){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
        
    }
    
    void update(int i, int val) {
        int pos = i + length;
        tree[pos] =  val;
        
        while(pos > 0){
            int left = pos;
            int right = pos;
            if(pos%2 == 0){
                right = pos+1;
            }else{
                left = pos-1;
            }
            tree[pos/2] = tree[left] + tree[right];
            pos = pos/2;
        }
    }
    
    int sumRange(int i, int j) {
        int l = i + length;
        int r = j + length;
        int sum = 0;
        
        while(l <= r){
            if(l%2 == 1){
                sum += tree[l];
                l++;
            }
            if(r%2 == 0){
                sum += tree[r];
                r--;
            }
            l = l/2;
            r = r/2;
        }
        
        return sum;
    }
private:
    int * tree;
    int length;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */