#include <bits/stdc++.h>
#define debug(args...) printf(args);fflush(stdout)
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
#define mset(a,b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]:" << x << endl;

void mergeSort(vector<int>& a);
void mergeArray(vector<int>&, vector<int>&, vector<int>&);

int main() {

  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
  vector<int> a{1,102,-3,11,7,-3};
  
  mergeSort(a);

  for(int i = 0; i <  (int)a.size(); ++i)  {
    cout << a[i] << endl;  
  }

  return 0;
}

void mergeSort(vector<int>& a) {
  int size = a.size();
  
  if(size < 2) {
    return;
  }

  int mid = size/2;

  vector<int> left(mid, 0);
  vector<int> right(size - mid, 0);

  for (int i = 0; i < mid; ++i) {
    left[i] = a[i];
  }

  for (int i = mid; i < size; ++i) {
    right[i-mid] = a[i];
  }

  mergeSort(left);
  mergeSort(right);

  mergeArray(a, left, right);
}

void mergeArray(vector<int>& a, vector<int>& left, vector<int>& right) {
  int leftSize = left.size();
  int rightSize = right.size();


  int l = 0, r = 0, m = 0;

  while(l < leftSize && r < rightSize) {
    if (left[l] <= right[r]) {
      a[m] = left[l];
      ++l;
    } else {
      a[m] = right[r];
      ++r;
    }
    ++m;
  }


  while(l < leftSize) {
    a[m] = left[l];
    ++l;
    ++m;
  }
  
  while(r < rightSize) {
    a[m] = right[r];
    ++r;
    ++m;
  }
}
