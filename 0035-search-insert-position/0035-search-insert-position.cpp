class Solution {
public:
    int binarySearch(vector<int>&nums , int target , int si , int end){

        if (si > end) { return si; }
        int mid = si+(end-si)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid] > target){
            return binarySearch(nums,target , si , mid-1);
        }
        else{
            return binarySearch(nums,target , mid+1 , end);
        }

        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,target , 0, nums.size()-1);
    }
};