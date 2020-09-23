#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int solve(string a, string b, int n, int m) {
	if (n == 0 || m == 0) {
		return 0;
	}
	if (a[n - 1] == b[m - 1]) {
		return (1 + solve(a, b, n - 1, m - 1));
	}
	else {
		return max(solve(a, b, n, m - 1), solve(a, b, n - 1, m));
	}
}

int main() {
	string a, b;
	cin >> a;
	int n = a.length();
	int m = n;
	b = a;
	reverse(a.begin(), a.end());
	cout << solve(a, b, n, m) << endl;

	long long int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n][m];

	return 0;
}