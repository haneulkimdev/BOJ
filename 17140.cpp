// http://boj.kr/ed7fc2b8fdbf40b1bb46b51b538a2d91
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int r, c, k;
int a[101][101];
int n = 3;
int m = 3;

void flip() {
  for (int i = 1; i <= max(n, m); i++)
    for (int j = i + 1; j <= max(n, m); j++) swap(a[i][j], a[j][i]);
  swap(n, m);
}

void calc() {
  for (int i = 1; i <= n; i++) {
    int freq[101] = {};
    for (int j = 1; j <= m; j++) freq[a[i][j]]++;
    vector<pair<int, int>> tmp;
    for (int num = 1; num <= 100; num++) {
      if (freq[num] == 0) continue;
      tmp.push_back({freq[num], num});
    }
    sort(tmp.begin(), tmp.end());
    int j = 1;
    for (auto t : tmp) {
      if (j > 100) break;
      a[i][j++] = t.Y;
      a[i][j++] = t.X;
    }
    m = max(m, j - 1);
    fill(a[i] + j, a[i] + m + 1, 0);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int ans = 0;
  while (a[r][c] != k && ans <= 100) {
    bool is_flipped = false;
    if (n < m) {
      flip();
      is_flipped = true;
    }
    calc();
    if (is_flipped) flip();
    ans++;
  }
  if (ans > 100) ans = -1;
  cout << ans;
}