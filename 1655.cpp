// http://boj.kr/a5ece6bc3f8945689fce30306e09a697
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (max_heap.size() > min_heap.size())
      min_heap.push(x);
    else
      max_heap.push(x);
    if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
      min_heap.push(max_heap.top());
      max_heap.pop();
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
    cout << max_heap.top() << '\n';
  }
}