// http://boj.kr/d72af3529e2a4c62b0f6f1f8647e944e
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> child[50];
int del;
int root;
int go(int x) {
  if (x == del) return 0;
  if (child[x].empty()) return 1;
  if (child[x].size() == 1 && child[x][0] == del) return 1;
  int ret = 0;
  for (auto nxt : child[x]) ret += go(nxt);
  return ret;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    if (p == -1) {
      root = i;
      continue;
    }
    child[p].push_back(i);
  }
  cin >> del;
  cout << go(root) << '\n';
}