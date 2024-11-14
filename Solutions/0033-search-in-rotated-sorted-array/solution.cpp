class Solution {
public:
    int binSearch(vector<int>& nums, int l, int r, int target) {
        while(l < r) {
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid;
        }
        if(nums[l] == target) return l;
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1 || nums[0] < nums[n-1]) return binSearch(nums, 0, n-1, target);
        int l = 0, r = n-1;
        int point;
        while(l <= r) {
            int mid = (l+r)/2;
            if(nums[mid] > nums[mid+1]) {
                point = mid;
                break;
            } else if(nums[mid] < nums[r]) r = mid;
            else l = mid+1;
        }
        int one = binSearch(nums, 0, point, target);
        int two = binSearch(nums, point+1, n-1, target);
        if(one != -1) return one;
        if(two != -1) return two;
        return -1;
    }
};
