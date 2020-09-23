#include<bits/stdc++.h>

using namespace std;

vector<int>solu;
vector<int>arr;

void printsolution(int n) {
	for (auto x : solu) {
		cout << x << " ";
	}
	cout << endl;
}

bool issafe(int sum, int target, int val, int m) {
	if (sum > m) {
		return false;
	}
	if (target + sum < m) {
		return false;
	}
	return true;
}

bool combination(int sum, int target, int i, int n, int m) {
	if (sum == m) {
		printsolution(n);
		return true;
	}
	cout << sum << " " << target << " " << i << endl;

	solu[i] = 1;
	sum = sum + arr[i];
	target = target - arr[i];
	if (issafe(sum, target, arr[i], m)) {
		if (combination(sum, target, i + 1, n, m)) {
			return true;
		}
		cout << "back" << " " << sum << " " << target << " " << i << endl;
		target = target - arr[i + 1];
		combination(sum, target, i + 2, n, m);
	}

	return false;
}


int main() {
	int n, t, val;
	cin >> n;
	cin >> t;
	for (int i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
	}
	for (int i = 0; i < n; ++i)
	{
		solu.push_back(0);
	}
	int h = accumulate(arr.begin(), arr.end(), 0);
	combination(0, h, 0, n, t);
	return 0;
}
