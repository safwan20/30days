#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		int n;
		vector<vector<int>>arr;
		n = numRows;

		if (n == 0) {
			return arr;
		}

		vector<int>temp;
		temp.push_back(1);
		arr.push_back(temp);

		if (n == 1) {
			return arr;
		}

		vector<int>hemp;
		hemp.push_back(1);
		hemp.push_back(1);
		arr.push_back(hemp);

		for (int i = 2; i < n ; i++) {
			vector<int>temp;
			temp.push_back(1);
			for (int j = 0; j < i - 1 ; j++) {
				temp.push_back(arr[i - 1][j] + arr[i - 1][j + 1]);
			}
			temp.push_back(1);
			arr.push_back(temp);
		}

		for (auto x : arr) {
			for (auto y : x) {
				cout << y << " ";
			}
			cout << endl;
		}

		return arr;
	}
};


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	Solution s;
	s.generate(n);

	return 0;
}