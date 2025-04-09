#include<bits/stdc++.h>

class Solution {
	public:
		int jump(std::vector<int>& nums) {
			int n = nums.size();
			int jumps = 0;
			int currentEnd = 0;
			int farthest = 0;
			
			for(int i = 0; i < n-1; ++i){
				farthest = std::max(farthest, i + nums[i]);
				if(i == currentEnd){
					jumps++;
					currentEnd = farthest;
				}
			}
			return jumps;
		}
	};

int main(){
	std::vector<int> nums;
	for(int i = 0; i < nums.size(); i++){
		std::cin >> nums[i];
	}

	std::cout<<"Return min jumps: ";
	Solution s;
	std::cout<<s.jump(nums);
}
