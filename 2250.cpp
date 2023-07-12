// http://boj.kr/970759a9f5844db79141c917f80c72f1
#include <bits/stdc++.h>
using namespace std;

int n;
int lc[10001];
int rc[10001];
int p[10001];
int depth[10001];
int idx = 1;
int mnidx[10001];
int mxidx[10001];

void inorder(int cur) {
  depth[cur] = depth[p[cur]] + 1;
  if (lc[cur] != -1) inorder(lc[cur]);
  mnidx[depth[cur]] = min(mnidx[depth[cur]], idx);
  mxidx[depth[cur]] = max(mxidx[depth[cur]], idx);
  idx++;
  if (rc[cur] != -1) inorder(rc[cur]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(mnidx, mnidx + 10001, 0x7fffffff);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int c, l, r;
    cin >> c >> l >> r;
    lc[c] = l;
    rc[c] = r;
    if (l != -1) p[l] = c;
    if (r != -1) p[r] = c;
  }
  int root = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i] == 0) {
      root = i;
      break;
    }
  }
  inorder(root);
  int mx_level = 0;
  int mx_width = 0;
  for (int level = 1; mnidx[level] != 0x7fffffff; level++) {
    int width = mxidx[level] - mnidx[level] + 1;
    if (width > mx_width) {
      mx_level = level;
      mx_width = width;
    }
  }
  cout << mx_level << ' ' << mx_width;
}