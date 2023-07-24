// http://boj.kr/b33299ada7af47a688be72fe66d775fb
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
vector<int> child[1000];
int deg[1000];
int n, m;
unordered_map<string, int> s2i;
string i2s[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> i2s[i];
  sort(i2s, i2s + n);
  for (int i = 0; i < n; i++) s2i[i2s[i]] = i;
  cin >> m;
  while (m--) {
    string x, y;
    cin >> x >> y;
    adj[s2i[y]].push_back(s2i[x]);
    deg[s2i[x]]++;
  }
  vector<int> root;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) root.push_back(i);
    sort(adj[i].begin(), adj[i].end());
    for (int nxt : adj[i])
      if (deg[nxt] - deg[i] == 1) child[i].push_back(nxt);
  }
  cout << root.size() << '\n';
  for (auto x : root) cout << i2s[x] << ' ';
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << i2s[i] << ' ' << child[i].size() << ' ';
    for (int nxt : child[i]) cout << i2s[nxt] << ' ';
    cout << '\n';
  }
}