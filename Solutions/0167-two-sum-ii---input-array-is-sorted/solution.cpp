class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while(1) {
        int current = numbers[l] + numbers[r];
        if(current == target) return {l+1, r+1};
        else if(current < target) l++;
        else r--;
    }
}
};
