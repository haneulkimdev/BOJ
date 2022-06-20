// http://boj.kr/607a2c7b96be43349ddcb242d8bf61cc
#include <bits/stdc++.h>
using namespace std;

int n;
string a[50];

bool cmp(const string &a, const string &b) {
  if (a.size() != b.size()) return a.size() < b.size();
  int diff = 0;
  for (int i = 0; i < a.size(); i++)
    if (isdigit(a[i])) diff += (a[i] - '0');
  for (int i = 0; i < b.size(); i++)
    if (isdigit(b[i])) diff -= (b[i] - '0');
  if (diff != 0) return diff < 0;
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) cout << a[i] << '\n';
}