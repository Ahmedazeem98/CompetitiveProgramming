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
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	ll x, t;
	while (cin >> x)
	{
		ll a, mx = -1;
		set<ll>st;
		rep(i, x)
		{
			ll m;
			cin >> m;
			st.insert(m);
			mx = max(mx, m);
		}
		vector<ll>v(st.begin(),st.end());
		vector<ll>::iterator it;
		cin >> t;
		rep(i, t)
		{
			bool find = 0;
			cin >> a;
			it = lower_bound(all(v), a);
			int idx = it - v.begin();
			if (binary_search(allv(v),a))
				find = 1;
			idx--;
			if (idx >= 0 && idx < vz)
				cout << v[idx] << " ";
			else
			{
				if (a>x)
					cout << v[x - 1] << " ";
				else
					cout << "X" << " ";
			}
			if (find)
				idx += 2;
			else
				idx++;
			if (idx >= 0 && idx < vz)
				cout << v[idx] << endl;
			else
				cout << "X" << endl;
		}

	}
	return 0;
}
