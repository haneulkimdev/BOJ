// http://boj.kr/072f1c9f7a044a45925469fc3ceb5d8f
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> v;
  while (n--) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    v.push_back(stoll(s));
  }
  sort(v.begin(), v.end());
  for (long long i : v) cout << i << '\n';
}