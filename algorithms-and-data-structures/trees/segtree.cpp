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