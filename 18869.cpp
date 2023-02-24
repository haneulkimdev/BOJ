// http://boj.kr/678a9e81adb141bc9381263615e3a344
#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[100][100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    vector<int> uni;
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      uni.push_back(arr[i][j]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (int j = 0; j < n; j++)
      arr[i][j] = lower_bound(uni.begin(), uni.end(), arr[i][j]) - uni.begin();
  }
  int ans = 0;
  for (int i = 0; i < m - 1; i++)
    for (int j = i + 1; j < m; j++)
      ans += equal(arr[i], arr[i] + n, arr[j]);
  cout << ans;
}