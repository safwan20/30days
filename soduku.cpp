#include<bits/stdc++.h>

using namespace std;

int s[10001][10001];

void printsolution(int n) {
	cout << endl;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cout << s[row][col] << " ";
		}
		cout << endl;
	}
}

bool issafe(int v, int r, int c, int n) {

	for (int col = 0; col < n; col++) {
		if (s[r][col] == v) {
			return false;
		}
	}

	for (int row = 0; row < n; row++) {
		if (s[row][c] == v) {
			return false;
		}
	}

	int row_start = (r / 3) * 3;
	int col_start = (c / 3) * 3;
	for (int row = row_start; row < row_start + 3; row++)
	{
		for (int col = col_start; col < col_start + 3; col++)
		{
			if (s[row][col] == v)
				return false;
		}
	}

	return true;
}

bool soduku(int i, int j, int n) {
	if (i == n - 1 && j == n) {
		cout << i << " " << j << endl;
		printsolution(n);
		return true;
	}
	if (j == n) {
		i++; j = 0;
	}
	if (s[i][j] != 0) {
		soduku(i, j + 1, n);
		return false;
	}
	for (int k = 1; k <= n; k++) {
		if (issafe(k, i, j, n)) {
			s[i][j] = k;
			if (soduku(i, j + 1, n)) {
				return true;
			}
			s[i][j] = 0;
		}
	}
	return false;
}


int main() {
	int n, val;
	n = 9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	soduku(0, 0, n);
	return 0;
}
