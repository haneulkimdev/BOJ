// http://boj.kr/636d50f9708e4bb885124a82cc5fc17c
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      pq.push(x);
    }
    ll ans = 0;
    while (pq.size() > 1) {
      ll a = pq.top();
      pq.pop();
      ll b = pq.top();
      pq.pop();
      ans += a + b;
      pq.push(a + b);
    }
    cout << ans << '\n';
  }
}