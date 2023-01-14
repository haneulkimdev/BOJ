// http://boj.kr/ad0787a1823d4c72b59d5fac83f2baf2
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n;
vector<int> pos, neg;

void func(vector<int> v) {
  while (v.size() > 1) {
    int tmp = v.back();
    v.pop_back();
    ans += tmp * v.back();
    v.pop_back();
  }
  if (!v.empty()) ans += v.back();
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    if (t == 1)
      ans++;
    else if (t > 0)
      pos.push_back(t);
    else
      neg.push_back(t);
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end(), greater<int>());
  func(pos);
  func(neg);
  cout << ans;
}