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
pair<ll, ll> search(vector<ll>v, ll x)
{
	ll low = 0, high = vz - 1, a = -1 * 1e17, b = 1e17;
	while (low <= high)
	{
		int md = (low + high) / 2;
		int val = v[md];
		if (v[md] > x)
		{
			b = min(b, v[md]);
			high = md - 1;
		}
		else if (v[md] < x)
		{
			a = max(a, v[md]);
			low = md+ 1;
		}
		else
		{
			if (md)
				a = max(a, v[md - 1]);
			if (md + 1 < vz)
				b = min(b, v[md + 1]);
			break;
		}
	}
	return{ a, b };
}
int main()
{
	file();
	int x, y;
	while (cin >> x)
	{
		vector<ll>v;
		map<ll, int>mp;
		int idx = 0;
		rep(i, x)
		{
			int a;
			cin >> a;
			if (mp[a] == 0)
				v.push_back(a), mp[a] = 1;
		}
		cin >> y;
		while (y--)
		{
			ll n;
			cin >> n;
			pair<ll, ll>ans = search(v, n);
			if (ans.first != ll(-1*1e17))
				cout << ans.first << " ";
			else
				cout << 'X' << " ";
			if (ans.second != ll(1e17))
				cout << ans.second << "\n";
			else
				cout << 'X' << "\n";
		}
	}
	return 0;
}
