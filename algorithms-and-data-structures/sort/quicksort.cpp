#include <bits/stdc++.h>
#define debug(args...)                                                         \
  printf(args);                                                                \
  fflush(stdout)
using namespace std;

typedef long long ll;
typedef double db;
typedef float fl;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

#define pb push_back
#define mk make_pair
#define se second
#define fi first
#define eb emplace_back
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]:" << x << endl;

void quicksort(vector<int> &a, int start, int end);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> a{1, 102, -3, 11, 7, -3};

  quicksort(a, 0, a.size() - 1);

  for (int i = 0; i < (int)a.size(); ++i) {
    cout << a[i] << endl;
  }

  return 0;
}

void quicksort(vector<int> &a, int start, int end) {
  // using last as pivot, can be optimized (first, mid, last method)
  int pivot = a[(start + end) / 2];

  int i = start, j = end;
  while (i < j) {
    while (a[i] < pivot && i < end) {
      i++;
    }

    while (a[j] > pivot && j > start) {
      j--;
    }

    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }

    if (j > start)
      quicksort(a, start, j + 1);
    if (i < end)
      quicksort(a, i, end);
  }
}
