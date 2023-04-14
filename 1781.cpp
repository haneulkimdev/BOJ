// http://boj.kr/158229860f0d41f7a0459e78510e5898
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
pair<int, int> cup[200000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> cup[i].X >> cup[i].Y;
  sort(cup, cup + n);
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(cup[i].Y);
    while (pq.size() > cup[i].X) pq.pop();
  }
  int ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
}