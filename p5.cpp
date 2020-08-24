class Solution {
public:

	int maxSubArray(vector<int>& nums) {
		vector<int>dp;
		dp.push_back(nums[0]);


		for (int i = 1; i < nums.size(); i++) {
			dp.push_back(max(nums[i], dp[i - 1] + nums[i]));
		}


		return *max_element(dp.begin(), dp.end());


	}
};
