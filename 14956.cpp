// http://boj.kr/32989078a17043fb8a9f115fef5cc912
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<int, int> func(int n, int m) {
  if (n == 2) {
    if (m == 0) return {1, 1};
    if (m == 1) return {1, 2};
    if (m == 2) return {2, 2};
    if (m == 3) return {2, 1};
  }
  int half = n / 2;
  int square = m / (half * half);
  auto coor = func(half, m % (half * half));
  if (square == 0) return {coor.Y, coor.X};
  if (square == 1) return {coor.X, half + coor.Y};
  if (square == 2) return {half + coor.X, half + coor.Y};
  return {n + 1 - coor.Y, half + 1 - coor.X};
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  auto ans = func(n, m - 1);
  cout << ans.X << ' ' << ans.Y;
}