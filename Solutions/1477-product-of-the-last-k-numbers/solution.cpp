class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) nums.clear();
        else {
            int last = 1;
            if(!nums.empty()) last = nums[nums.size()-1];
            nums.push_back(last * num);
        }
    }
    
    int getProduct(int k) {
        if(nums.size() < k) return 0;
        else if(nums.size() == k) return nums[k-1];
        else {
            int n = nums.size() - 1;
            return nums[n] / nums[n-k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
