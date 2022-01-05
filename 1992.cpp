// http://boj.kr/d409e8ff2855440b878529bda3fd4eef
#include <bits/stdc++.h>
using namespace std;

string pic[64];
int n;

bool chk(int n, int x, int y) {
  for (int i = x; i < x + n; i++)
    for (int j = y; j < y + n; j++)
      if (pic[i][j] != pic[x][y]) return false;
  return true;
}

void quadtree(int n, int x, int y) {
  if (chk(n, x, y)) {
    cout << pic[x][y];
    return;
  }
  cout << '(';
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) quadtree(n / 2, x + i * n / 2, y + j * n / 2);
  cout << ')';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> pic[i];
  quadtree(n, 0, 0);
}