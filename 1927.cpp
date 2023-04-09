// http://boj.kr/1107a89ec1c44d0ab89980f766885d14
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, greater<int>> pq;
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