class Solution {
public:
    bool canJump(vector<int>& nums) {
        int targetjump = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(targetjump <= nums[i] + i)
             targetjump = i;
        }
        return targetjump == 0;
    }
};
