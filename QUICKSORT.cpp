#include    <iostream>
#include    <time.h>
#include    <cstdlib>
#include    <ctime>

using namespace std;

const int nTest = 10;
const int N = 1e6 + 5;

int n;
double arr[N];

void read();
void quicksort(int l, int r);
void checker();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    
    freopen("./output/quicksort/out.txt", "w", stdout);

    for (int iTest = 1; iTest <= nTest; iTest++)
    {
        freopen(("./input/inp" + to_string(iTest) + ".txt").c_str(), "r", stdin);

        read();

        clock_t start = clock();
        quicksort(0, n-1);
        clock_t end = clock();

        checker();
        cout << (double) (end - start) / CLOCKS_PER_SEC << '\n';
    }

    return 0;
}

void read() {   
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> arr[i]; 
}

void quicksort(int l, int r) {
    double x = arr[rand() % (r - l + 1) + l];
    int i = l, j = r;

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }while (i <= j);

    if (l < j) quicksort(l, j);
    if (i < r) quicksort(i, r);
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
