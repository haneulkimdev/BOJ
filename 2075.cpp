// http://boj.kr/0f148a41c97e40cc8ca994011c107887
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    int x;
    cin >> x;
    pq.push(x);
    if (pq.size() > n) pq.pop();
  }
  cout << pq.top();
}