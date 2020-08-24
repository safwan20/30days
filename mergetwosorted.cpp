#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void Merge(vector<int>& a, vector<int>& b) {

		vector<int>final;
		int i = 0, j = 0;

		while (i != a.size() &&  j != b.size()) {
			if (a[i] <= b[j]) {
				final.push_back(a[i]);
				i += 1;
			}
			else {
				final.push_back(b[j]);
				j += 1;
			}
		}

		if (i < a.size()) {

			for (int r = i; r < a.size(); r++) {
				final.push_back(a[r]);
			}

		}

		if (j < b.size())
		{
			for (int r = j; r < b.size(); r++) {
				final.push_back(b[r]);
			}
		}


		for (auto x : final) {
			cout << x << " ";
		}

	}
};

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int val, t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		Solution s;
		vector<int>a, b;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}

		for (int i = 0; i < m; i++) {
			cin >> val;
			b.push_back(val);
		}

		s.Merge(a, b);
		cout << endl;

	}

	return 0;
}