#include  <iostream>
#include  <time.h>
#include  <cstdlib>
#include  <algorithm>

using namespace std;

const int nTest = 10;
const int N = 1e6;

int n;
double arr[N];

void read();
void mergesort(double a[], int l, int r);
void checker();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  

  freopen("./output/mergesort/out.txt", "w", stdout);

  for (int iTest = 1; iTest <= nTest; iTest++)
  { 
    freopen(("./input/inp" + to_string(iTest) + ".txt").c_str(), "r", stdin);
    
    read();

    clock_t start = clock();
    mergesort(arr, 0, n-1);
    clock_t end = clock();
    
    // checker();
    cout << (double) (end - start) / CLOCKS_PER_SEC << '\n';
  }

  return 0;
}

void read() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

void mergesort(double a[], int l, int r) {
  if (l >= r) 
    return;

  if (r - l == 1)
  {
    if (a[l] > a[r]) swap(a[l], a[r]);
    return;
  }

  int mid = (l + r) >> 1;
  mergesort(a, l, mid);
  mergesort(a, mid + 1, r);
  
  static double tmp[N];

  int len = r - l + 1;
  merge(a + l, a + mid + 1, a + mid + 1, a + r + 1, tmp);
  copy(tmp, tmp + len, a + l);
}

void checker() {
    double pre_x, x;
    pre_x = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (pre_x > arr[i]) 
        {
            cout << "N";
            return;
        }
        pre_x = arr[i];
    }

}
