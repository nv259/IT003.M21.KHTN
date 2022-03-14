#include <bits/stdc++.h>

#define ll long long
#define rand rd

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const string NAME = "inp";
const int nTest = 8;
const int n = 1e6;

ll Rand(ll lo, ll hi)
{
  assert(lo <= hi);
  return lo + 1LL * rd() * rd() % (hi - lo + 1);
}

void gen_increasing_array();
void gen_decreasing_array();
void gen_random_array();

int main()
{
  srand(time(NULL));
  gen_increasing_array();
  gen_decreasing_array();
  gen_random_array();

  return 0;
}

void gen_increasing_array()
{
  ofstream inp("./input/inp1.txt");
  inp << n << "\n";
  double divident = 13.4;
  long long x = Rand(-1e5, 0);
  inp << fixed << setprecision(6);

  for (int i = 0; i < n; i++)
  {
    inp << (double) x / divident << " ";
    x = Rand(x + 1, x + 1e1);
  }
  inp.close();
}

void gen_decreasing_array()
{
  ofstream inp("./input/inp2.txt");
  inp << n << "\n";
  double divident = 13.3;
  long long x = Rand(1e5, 1e6);
  inp << fixed << setprecision(6);
  
  for (int i = 0; i < n; i++)
  {
    inp << 1.0 * x / divident << " ";
    x = Rand(x - 1e1, x - 1);
  }
  inp.close();
}

void gen_random_array()
{
  for (int iTest = 3; iTest < nTest + 3; iTest++)
  {
    ofstream inp(("./input/inp" + to_string(iTest) + ".txt").c_str());
    inp << n << "\n";
    double divident = 3.8;
    inp << fixed << setprecision(6);
    long long x;

    for (int i = 0; i < n; i++)
    {
      x = Rand(-1e6, 1e6);
      inp << (double) x / divident << " ";
    }
    inp.close();
  }
}

