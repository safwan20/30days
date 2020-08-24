#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		if (prices.size() == 0) {
			return 0;
		}

		int min = prices[0];
		int max = 0;

		// cout << min << " " << max;

		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > min) {
				if ( (prices[i] - min) > max) {
					max = prices[i] - min;
				}
			}
			else {
				min = prices[i];
			}
		}

		return max;

	}
};

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>arr;
	int n, val;
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
	}

	Solution s;
	cout << s.maxProfit(arr);

	return 0;
}