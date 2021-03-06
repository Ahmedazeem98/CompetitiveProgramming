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
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int x, y;
vector<int>v(1000);
bool valid(ll m)
{
	ll c = 0, f = m;
	rep(i, x)
	{
		if (v[i] > m)
			return 0;
		if (v[i] > f)
		{
			c++, f = m;
			if (c == y)
				return 0;
		}
		f -= v[i];
	}
	return 1;
}
ll mn;
ll search()
{
	ll l = 1, r = 1000000000;
	while (l <= r)
	{
		ll md = (l + r) / 2;
		bool t = valid(md);
		if (t)
			mn = md, r = md - 1;
		else
		l = md + 1;
	}
	return mn;
}
int main()
{
	fast();
	while (cin >> x >> y)
	{
		rep(i, x)
			cin >> v[i];
		cout << search() << endl;
	}
	return 0;
}
