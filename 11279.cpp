// http://boj.kr/6c13ea6c7e2a4d9e8ad63926262ac4c6
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int> pq;
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