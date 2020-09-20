#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int mid = matrix.size() / 2;
		int temp, pemp;

		for (int i = 0; i < mid; i++) {
			for (int j = i; j < n - (j + 2); j++) {
				temp = matrix[i][j];
				for (int k = 0; k < 4; k++) {
					if (k == 0) {
						temp = matrix[i][j];
						pemp = matrix[i][n - (j + 1)];
						matrix[i][n - (j + 1)] = temp;
					}
					else if (k == 1) {

					}
					else if (k == 2) {

					}
					else {

					}

				}
			}
		}


	}
};



int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int val, n;
	vector<vector<int>> matrix;
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int>temp;
		for (int j = 0; j < n; j++) {
			cin >> val;
			temp.append(val);
		}
		matrix.append(temp);
	}


	rotate(matrix);

	return 0;
}