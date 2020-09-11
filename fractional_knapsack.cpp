#include <bits/stdc++.h>


using namespace std;

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    vector<tuple<int, int, double>>arr;
    int val, wei, w, n, ans = 0;
    double temp;
    cin >> n >> w;

    for (int i = 0; i < n; i++) {
      cin >> val >> wei;
      temp = val / wei;
      arr.push_back(make_tuple(temp, wei, val));
    }

    sort(arr.begin(), arr.end(), greater<>());

    for (int i = 0; i < arr.size(); i++)
    {
      if (get<1>(arr[i]) <= w) {
        ans += get<2>(arr[i]);
        w = w - get<1>(arr[i]);
      }
      else {
        ans += (w * (get<2>(arr[i]))) / get<1>(arr[i]);
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}