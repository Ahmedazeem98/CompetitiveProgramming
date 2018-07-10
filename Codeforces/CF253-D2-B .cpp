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
#define allvr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
void fast()
{
#ifndef ONLINE_JUDGE

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
vector<int>ans;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	fast();
	int x;
	cin >> x;
	map<int, int>mp;
	map<int, bool>vis;
	map<int, bool>vis1;
	vector<int>v(x);
	rep(i, x)
		cin >> v[i], mp[v[i]]++;
	sort(allv(v));
	vector<int>::iterator it;
	int mn = INT_MAX, s = 0;
	for (int i = 0; i < x; i++)
	{
		if (vis1[v[i]])
			continue;
		vis1[v[i]] = 1;
		it = lower_bound(allv(v), v[i] * 2);
		if (it == v.end())
			mn = min(mn, s);
		else
		{
			int idx = it - v.begin();
			if (v[idx] <= 2 * v[i])
				idx += mp[v[idx]] - 1, mn = min(mn, s + (x - (idx + 1)));
			else
				mn = min(mn, s + (x - (idx)));
		}
		if (!vis[v[i]])
			s += mp[v[i]], vis[v[i]] = 1;
	}
	cout << mn;
	return 0;
}
