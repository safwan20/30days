#include<bits/stdc++.h>

using namespace std;

vector<int> graph[10001];
vector<int>solu;

void printsolution(int n) {
	for (auto x : solu) {
		cout << x << " ";
	}
	cout << endl;
}

bool issafe(int node, int v) {
	for (auto x : graph[node]) {
		if (solu[x] == v) {
			return false;
		}
	}
	return true;
}

bool colour(int node, int n, int m) {
	if (node > n) {
		return true;
	}
	for (int k = 1; k <= m; k++) {
		if (issafe(node, k)) {
			solu[node] = k;
			if (colour(node + 1, n, m)) {
				return true;
			}
			solu[node] = 0;
		}
	}
	return false;
}


bool answer(int n) {
	for (int i = 1; i <= n; i++) {
		for ( auto x : graph[i]) {
			if (solu[i] == solu[x]) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int m, n, e, val, u, v;
	cin >> n;
	cin >> m;
	cin >> e;
	for (int i = 0; i < e; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i <= n; ++i)
	{
		solu.push_back(0);
	}
	colour(1, n, m);
	cout << answer(n);
	return 0;
}
