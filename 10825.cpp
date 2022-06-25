// http://boj.kr/eba69031479640baa454b1fd511ae766
#include <bits/stdc++.h>
using namespace std;

bool cmp(const tuple<string, int, int, int> &a,
         const tuple<string, int, int, int> &b) {
  if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
  if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
  if (get<3>(a) != get<3>(b)) return get<3>(a) > get<3>(b);
  return get<0>(a) < get<0>(b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<string, int, int, int>> v;
  while (n--) {
    string s;
    int a, b, c;
    cin >> s >> a >> b >> c;
    v.push_back({s, a, b, c});
  }
  sort(v.begin(), v.end(), cmp);
  for (auto t : v) cout << get<0>(t) << '\n';
}