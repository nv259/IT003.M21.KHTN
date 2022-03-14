#include    <iostream>
#include    <time.h>
#include    <cstdlib>
#include    <algorithm>

using namespace std;

const int nTest = 10;
const int N = 1e6;

int n;
double arr[N];

void read();
void std_c_sort();
void checker();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    
    freopen("./output/std_c_sort/out.txt", "w", stdout);

    for (int iTest = 1; iTest <= nTest; iTest++)
    {
        freopen(("./input/inp" + to_string(iTest) + ".txt").c_str(), "r", stdin);

        read();

        clock_t start = clock();
        std_c_sort();
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

void std_c_sort() {
    sort(arr, arr+n);
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
