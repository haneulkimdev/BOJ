// http://boj.kr/4d24ed616bf449299421e5c5f0a1eba8
#include <bits/stdc++.h>
using namespace std;

int n;
int lc[26];
int rc[26];

void preorder(int cur) {
  cout << char(cur + 'A');
  if (lc[cur] != -1) preorder(lc[cur]);
  if (rc[cur] != -1) preorder(rc[cur]);
}

void inorder(int cur) {
  if (lc[cur] != -1) inorder(lc[cur]);
  cout << char(cur + 'A');
  if (rc[cur] != -1) inorder(rc[cur]);
}

void postorder(int cur) {
  if (lc[cur] != -1) postorder(lc[cur]);
  if (rc[cur] != -1) postorder(rc[cur]);
  cout << char(cur + 'A');
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(lc, lc + 26, -1);
  fill(rc, rc + 26, -1);
  cin >> n;
  while (n--) {
    char c, l, r;
    cin >> c >> l >> r;
    if (l != '.') lc[c - 'A'] = l - 'A';
    if (r != '.') rc[c - 'A'] = r - 'A';
  }
  preorder(0);
  cout << '\n';
  inorder(0);
  cout << '\n';
  postorder(0);
  cout << '\n';
}