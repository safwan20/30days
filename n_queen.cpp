#include<bits/stdc++.h>

using namespace std;

int queen[10001][10001];

void printsolution(int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << queen[i][j] << " ";
		}
		cout << endl;
	}
}

bool issafe(int i, int j, int n) {

	for (int row = 0; row < i; row++) {
		if (queen[row][j] == 1) {
			return false;
		}
	}

	int x = i;
	int y = j;

	while (x >= 0 && y >= 0) {
		if (queen[x][y] == 1) {
			return false;
		}
		x--;
		j--;
	}

	x = i;
	y = j;
	while (x >= 0 && y < n) {
		if (queen[x][y] == 1) {
			return false;
		}
		x--;
		j++;
	}

	return true;
}



bool nqueen(int i, int n) {
	if (i == n) {
		printsolution(n);
		return true;
	}
	for (int j = 0; j < n; j++) {
		if (issafe(i, j, n)) {
			queen[i][j] = 1;
			if (nqueen(i + 1, n) == true) {
				return true;
			}
			queen[i][j] = 0;
		}
	}
	return false;
}

int main() {
	int n, val;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			queen[i][j] = 0;
		}
	}
	nqueen(0, n);
	return 0;
}
