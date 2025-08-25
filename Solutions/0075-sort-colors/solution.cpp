class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zer = 0, one = 0, two = 0;
        for(auto el: nums) 
            if(el == 0) zer++;
            else if(el == 1) one++;
            else two++;
        int i = 0;
        while(zer > 0) {
            nums[i++] = 0;
            zer--;
        }
        while(one > 0) {
            nums[i++] = 1;
            one--;
        }
        while(two > 0) {
            nums[i++] = 2;
            two--;
        }
    }
};
