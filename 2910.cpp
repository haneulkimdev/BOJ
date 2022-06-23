// http://boj.kr/5de342e9c28b4ac7b50cb3ec4a1ed000
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return a.Y > b.Y; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<pair<int, int>> freq;
  while (n--) {
    int tmp;
    cin >> tmp;
    bool state = true;
    for (auto &p : freq) {
      if (tmp == p.X) {
        p.Y++;
        state = false;
        break;
      }
    }
    if (state) freq.push_back({tmp, 1});
  }
  stable_sort(freq.begin(), freq.end(), cmp);
  for (auto p : freq) {
    while (p.Y--) {
      cout << p.X << ' ';
    }
  }
}