#include <bits/stdc++.h>

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, val, i, target, j;
	vector<int> nums, res;
	cin >> n;
	cin >> target;
	for (int k = 0; k < n; k++) {
		cin >> val;
		nums.push_back(val);
	}

	i = 0;
	j = nums.size() - 1;

	while (i <= j ) {
		if (nums[i] + nums[j] == target) {
			res.push_back(i);
			res.push_back(j);
			break;
		}
		else if (nums[i] + nums[j - 1] == target) {
			res.push_back(i);
			res.push_back(j);
			break;
		}
		else {
			i  = i  + 1;
		}
	}

	cout << res[0] << " " << res[1];

	return 0;
}