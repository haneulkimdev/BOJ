// http://boj.kr/0e512422830540a2a389e7d381071aa6
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (v.empty() || x > v.back()) {
      v.push_back(x);
    } else {
      auto it = lower_bound(v.begin(), v.end(), x);
      *it = x;
    }
  }
  cout << v.size();
}