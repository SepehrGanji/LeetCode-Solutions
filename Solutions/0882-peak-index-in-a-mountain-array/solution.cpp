class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n;
        while(1) {
            int mid = (l+r)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {
                l = mid;
            } else if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]) {
                r = mid;
            } else return mid;
        }
    }
};
