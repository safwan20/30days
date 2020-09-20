#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& arr) {
    int time = 0, cnt;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < arr[i].size(); j++) {

        if (arr[i][j] == 2) {
          cnt = 0;
          if (i != n - 1) {
            if (arr[i + 1][j] == 1) {
              cnt += 1;
              arr[i + 1][j] = 2;
            }
          }
          if (j != 0) {
            if (arr[i][j - 1] == 1) {
              cnt += 1;
              arr[i][j - 1] = 2;
            }
          }
          if (i != 0) {
            if (arr[i - 1][j] == 1) {
              cnt += 1;
              arr[i - 1][j] = 2;
            }
          }
          if (j != n - 1) {
            if (arr[i][j + 1] == 1) {
              cnt += 1;
              arr[i][j + 1] = 2;
            }
          }
          // cout << cnt << endl;
          if (cnt > 0) {
            time += 1;
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < arr[i].size(); j++) {
        if (arr[i][j] == 1) {
          time = -1;
          break;
        }
      }
    }

    return time;
  }
};


int main() {
  vector<vector<int>>arr;
  int n, m, val;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    vector<int>temp;
    for (int j = 0; j < m; j++) {
      cin >> val;
      temp.push_back(val);
    }
    arr.push_back(temp);
  }
  Solution s;
  cout << s.orangesRotting(arr);
  return 0;
}