// http://boj.kr/78274b6fc49948308f772bb45f09cbd1
#include <bits/stdc++.h>
using namespace std;

int n, r, m, k;
int t[200];
int d[2][100][100];
unordered_map<string, int> s2i;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r;
  r *= 2;
  for (int i = 0; i < n; i++) {
    fill(d[0][i], d[0][i] + n, 0x3fffffff);
    fill(d[1][i], d[1][i] + n, 0x3fffffff);
    d[0][i][i] = 0;
    d[1][i][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    s2i[s] = i;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    t[i] = s2i[s];
  }
  cin >> k;
  while (k--) {
    string type, s, e;
    int cost, a, b;
    cin >> type >> s >> e >> cost;
    cost *= 2;
    a = s2i[s];
    b = s2i[e];
    d[1][a][b] = min(d[1][a][b], cost);
    d[1][b][a] = min(d[1][b][a], cost);
    if (type == "Mugunghwa" || type == "ITX-Saemaeul" ||
        type == "ITX-Cheongchun")
      cost = 0;
    else if (type == "S-Train" || type == "V-Train")
      cost /= 2;
    d[0][a][b] = min(d[0][a][b], cost);
    d[0][b][a] = min(d[0][b][a], cost);
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[0][i][j] = min(d[0][i][j], d[0][i][k] + d[0][k][j]);
        d[1][i][j] = min(d[1][i][j], d[1][i][k] + d[1][k][j]);
      }
    }
  }
  int diff = r;
  for (int i = 1; i < m; i++) {
    diff += d[0][t[i - 1]][t[i]];
    diff -= d[1][t[i - 1]][t[i]];
  }
  if (diff < 0)
    cout << "Yes";
  else
    cout << "No";
}