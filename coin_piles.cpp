#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    vector<int>arr;
    int n, x, val, ans = 0;

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      cin >> val;
      arr.push_back(val);
    }
    // sort(arr.begin(), arr.end());

    int min_value = *min_element(arr.begin(), arr.end());

    for (auto y : arr) {
      if (y - min_value > x) {
        ans += (y - min_value) - x;
      }
    }
    // int i = 0, j = arr.size() - 1;

    // while (i < j) {
    //   if (abs(arr[i] - arr[j]) > x) {
    //     ans += arr[j] - (abs(arr[i] - arr[j]) );
    //     i++;
    //     j--;
    //   }
    //   else {
    //     i++;
    //   }
    // }
    cout << ans << endl;
  }

  return 0;
}