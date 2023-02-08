// http://boj.kr/833784522c654707a0de2e6aa415501f
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> nums;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < 1024; i++) {
    int brute = i;
    ll num = 0;
    for (int j = 9; j >= 0; j--) {
      if (brute % 2 == 1) num = 10 * num + j;
      brute /= 2;
    }
    nums.push_back(num);
  }
  sort(nums.begin(), nums.end());
  int n;
  cin >> n;
  if (n < nums.size())
    cout << nums[n];
  else
    cout << -1;
}