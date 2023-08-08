// http://boj.kr/d945a1b9616940ad85c738580ac4aa67
#include <bits/stdc++.h>
using namespace std;

class cmp {
 public:
  bool operator()(int a, int b) {
    if (abs(a) != abs(b)) return abs(a) > abs(b);
    return a > 0 && b < 0;
  }
};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, cmp> pq;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (x == 0) {
      if (pq.empty()) {
        cout << "0\n";
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(x);
    }
  }
}