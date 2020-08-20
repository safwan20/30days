#include <iostream>
#include<vector>

using namespace std;

int main() {
  vector<int>arr, dict;
  int val, n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    arr.push_back(val);
    dict.push_back(0);
  }
  dict.push_back(0);

  for (auto x : arr) {
    dict[x] += 1;
  }

  for (int i = 1; i < n + 1; i++) {
    if (dict[i] == 0)
      cout << "Missing number is : " << i << endl;
    if (dict[i] == 2)
      cout << "Repeating number is : " << i << endl;
  }

  return 0;
}