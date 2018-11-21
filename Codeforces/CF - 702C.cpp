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
#include <unordered_map>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include<cstdlib>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
void file()
{
#ifndef ONLINE_JUDGE

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
typedef long long ll;
#define endl "\n"
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define allvr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
int main()
{
	file();
	int n, m;
	cin >> n >> m;
	ll a = LLONG_MAX, b = LLONG_MIN;
	vector<ll>v(n), vv(m);
	rep(i, n)
		cin >> v[i], a = min(a, v[i]), b = max(b, v[i]);
	rep(i, m)
		cin >> vv[i];
	ll low = 0, high = 1e18, ans = INT_MAX;
	while (low <= high)
	{
		ll mn = LLONG_MAX, mx = LLONG_MIN;
		ll md = (low + high) / 2;
		rep(i, m)
			mn = min(mn, vv[i] - md), mx = max(vv[i] + md, mx);
		bool ok = 1;
		int idx1 = 0, idx2 = 0;
		while (idx1 < n && idx2 < m)
		{
			if (v[idx1] >= vv[idx2] - md  && v[idx1] <= vv[idx2] + md)
				idx1++;
			else
				idx2++;
		}
		if (mn > a || mx < b || (idx1 != n))
			low = md + 1;
		else
			high = md - 1, ans = min(ans, md);
	}
	cout << ans;
	return 0;
}
