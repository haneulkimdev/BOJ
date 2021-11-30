// http://boj.kr/9d6087e70ce24922986b975864770411
#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d) {
  int cur = 0;
  for (int i = 1; i + 1 < (int)tmp.size(); i++) {
    if (tmp[i] == ',') {
      d.push_back(cur);
      cur = 0;
    } else {
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  if (cur != 0) d.push_back(cur);
}

void print_result(deque<int>& d) {
  cout << '[';
  for (int i = 0; i < (int)d.size(); i++) {
    cout << d[i];
    if (i + 1 != (int)d.size()) cout << ',';
  }
  cout << "]\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    deque<int> d;
    int rev = 0;
    int n;
    bool is_error = false;
    string p, tmp;
    cin >> p;
    cin >> n;
    cin >> tmp;
    parse(tmp, d);
    for (auto c : p) {
      if (c == 'R')
        rev = 1 - rev;
      else if (c == 'D') {
        if (d.empty()) {
          is_error = true;
          break;
        }
        if (!rev)
          d.pop_front();
        else
          d.pop_back();
      }
    }
    if (is_error) {
      cout << "error\n";
    } else {
      if (rev) reverse(d.begin(), d.end());
      print_result(d);
    }
  }
}