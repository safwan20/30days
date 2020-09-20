#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    vector<tuple<int, int, int>>arr;
    vector<int>s, e, res;
    int n, val, ans = 1, now;

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> val;
      s.push_back(val);
    }
    for (int i = 0; i < n; i++) {
      cin >> val;
      e.push_back(val);
    }
    for (int i = 0; i < n; i++) {
      arr.push_back(make_tuple(e[i], s[i], i + 1));
    }

    sort(arr.begin(), arr.end());

    now = get<0>(arr[0]);

    res.push_back(get<2>(arr[0]));

    for (int i = 1; i < n; i++)
    {
      if (now < get<1>(arr[i])) {
        res.push_back(get<2>(arr[i]));
        now = get<0>(arr[i]);
      }
    }

    for (auto x : res) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}