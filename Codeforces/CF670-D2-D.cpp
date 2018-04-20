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
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//x = atoill(s.c_str())
void fast()
{
#ifndef ONLINE_JUDGE
	/*
	**    ** ** **    *********   ** ** **
	**    **          **     **   **
	**    **          *********   **
	**    **          **          **
	**    ** ** **    **          ** ** **

	*/
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

}
vector<ll>v(100000);
vector<ll>vv(100000);
ll mx = 0, x, k;
int search()
{
	ll l = 1, r = 10000000000, f = k;
	while (l <= r)
	{
		ll md = (l + r) / 2, f = k, g = md;
		rep(i, x)
		{
			if (vv[i] >= v[i] * md);
			else
			{
				if (f >= abs(vv[i] - (v[i] * md)))
					f -= abs(vv[i] - (v[i] * md));
				else
				{
					g = 0;
					break;
				}
			}

		}
		if (g == 0)
			r = md - 1;
		else
			l = md + 1;
		mx = max(g, mx);
	}
	return mx;
}
int main()
{
	fast();
	cin >> x >> k;
	rep(i, x)
		cin >> v[i];
	rep(i, x)
		cin >> vv[i];
	cout << search();
	return 0;
}
