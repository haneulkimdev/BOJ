// http://boj.kr/45c58e1ccd6346d58cb17fbf65077aff
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<pair<int, int>> S;
  S.push({100000001, 0});
  for (int i = 1; i <= n; i++) {
    int height;
    cin >> height;
    while (S.top().X < height) S.pop();
    cout << S.top().Y << ' ';
    S.push({height, i});
  }
}