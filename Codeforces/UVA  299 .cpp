#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
typedef long long ll;
const  double PI = 3.141592654;
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define allr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
//x = atoi(s.c_str())
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		int x, c = 0;
		cin >> x;
		vector<int>v(x);
		vector<int>vv(x);
		rep(i, x)
			cin >> v[i], vv[i] = v[i];
		sort(allv(vv));
		int i = 0, ans = 0;
		for (; i < x; i++)
		{
			int c = 0, j = i;
			for (; j < x; j++)
			{
				if (vv[i] != v[j])
					c++;
				else
					break;
			}
			int k = j;
			while (c--)
			{
				swap(v[k], v[k - 1]), ans++;
				k--;
			}
		}
		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}
	return 0;
}
