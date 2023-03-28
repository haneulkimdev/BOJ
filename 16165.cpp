// http://boj.kr/58339c89bf2d4621855567f1e05039bd
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<string, vector<string>> t2m;
  unordered_map<string, string> m2t;
  while (n--) {
    string team;
    cin >> team;
    int num;
    cin >> num;
    while (num--) {
      string member;
      cin >> member;
      t2m[team].push_back(member);
      m2t[member] = team;
    }
    sort(t2m[team].begin(), t2m[team].end());
  }
  while (m--) {
    string query;
    cin >> query;
    int q;
    cin >> q;
    if (q == 0)
      for (string member : t2m[query]) cout << member << '\n';
    else
      cout << m2t[query] << '\n';
  }
}