#include  <iostream>
#include  <time.h>
#include  <cstdlib>

using namespace std;

const int nTest = 10;
const int N = 1e6;

int n;
double arr[N];

void read();
void heaptify(int id, int i);
void heapsort();
void checker();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  

  freopen("./output/heapsort/out.txt", "w", stdout);

  for (int iTest = 1; iTest <= nTest; iTest++)
  { 
    freopen(("./input/inp" + to_string(iTest) + ".txt").c_str(), "r", stdin);
    
    read();

    clock_t start = clock();
    heapsort();
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

void heaptify(int id, int i) {
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if (l < id && arr[l] > arr[largest])
    largest = l;

  if (r < id && arr[r] > arr[largest]) 
    largest = r;

  if (largest != i) 
  {
    swap(arr[i], arr[largest]);
    heaptify(id, largest);
  }
}

void heapsort() {
  for (int i = n / 2 - 1; i >= 0; i--)
    heaptify(n, i);

  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);

    heaptify(i, 0);
  }
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
