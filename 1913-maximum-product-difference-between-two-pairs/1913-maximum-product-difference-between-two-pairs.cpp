class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size()-1;
        sort(nums.begin(),nums.end());
        if(nums.size() <4) return 0;
        return (nums[n] * nums[n-1] ) - (nums[0] *  nums[1]);
        
        
    }
};