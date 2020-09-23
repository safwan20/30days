#include<bits/stdc++.h>

using namespace std;

int maze[10001][10001];
int soln[10001][10001];
vector<char>res;


void printsolution(int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << soln[i][j] << " ";
		}
		cout << endl;
	}

	for (auto x : res) {
		cout << x;
	}
}

bool issafe(int x, int y, int n) {
	if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || soln[x][y] == 1)
		return false;
	return true;
}


bool mazehelp(int n, int x, int y) {
	if (x == n - 1 && y == n - 1) {
		soln[x][y] = 1;
		printsolution(n);
		return true;
	}

	// if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || soln[x][y] == 1) {
	// 	return;
	// }

	if (issafe(x, y, n) == true) {
		soln[x][y] = 1;
		if (mazehelp(n, x - 1, y)) {
			res.push_back('T');
			return true;
		}
		if (mazehelp(n, x + 1, y)) {
			res.push_back('D');
			return true;
		}
		if (mazehelp(n, x , y - 1)) {
			res.push_back('L');
			return true;
		}
		if (mazehelp(n, x, y + 1)) {
			res.push_back('R');
			return true;
		}

		soln[x][y] = 0;
		// res.pop_back();
		// mazehelp(n, x - 1, y)
		// mazehelp(n, x + 1, y);
		// mazehelp(n, x, y - 1);
		// mazehelp(n, x, y + 1);
	}
	return false;
}

void findpath(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			soln[i][j] = 0;
		}
	}
	mazehelp(n, 0, 0);
}

int main() {
	int n, val;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}
	findpath(n);
	return 0;
}
