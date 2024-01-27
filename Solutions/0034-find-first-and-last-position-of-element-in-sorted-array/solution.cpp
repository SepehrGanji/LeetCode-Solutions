class Solution {
public:
  int tmp_l = -1, tmp_r = -1;

  int binSearch(vector<int>& nums, int l, int r, int target) {
    while(l <= r) {
      int mid = (l + r) / 2;
      int el = nums[mid];
      if(el == target) return mid;
      else if(el < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    // does it exist?
    int idx = this->binSearch(nums, 0, nums.size() - 1, target);
    if(idx == -1) {
      return {-1, -1};
    }

    this->tmp_l = idx;
    this->tmp_r = idx;

    // searching left
    while(1) {
      int idx_l = this->binSearch(nums, 0, this->tmp_l - 1, target);
      if(idx_l == -1) break;
      this->tmp_l = idx_l;
    }
    // searching right
    while(1) {
      int idx_r = this->binSearch(nums, this->tmp_r + 1, nums.size() - 1, target);
      if(idx_r == -1) break;
      this->tmp_r = idx_r;
    }

    return {this->tmp_l, this->tmp_r};
  }
};

