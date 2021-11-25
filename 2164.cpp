// http://boj.kr/fc893565d8214bc0a410acc3232c0071
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  queue<int> Q;
  for (int i = 1; i <= n; i++) Q.push(i);
  while (Q.size() > 1) {
    Q.pop();
    Q.push(Q.front());
    Q.pop();
  }
  cout << Q.front();
}