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
	int x;
	string s;
	cin >> x >> s;
	int p1 = 0, p2 = 0, mn = INT_MAX, c;
	set<char>ss(all(s));
	c = ss.size();
	map<char, int>mp;
	while (p1 < sz && p2 < sz)
	{
		mp[s[p2]]++;
		if (mp.size() == c)
		{
			mn = min(abs(p1 - p2) + 1, mn);
			while (mp[s[p1]]>1)
				mp[s[p1]]--, p1++, mn = min(abs(p1 - p2) + 1, mn);
		}
		p2++;
	}
	if (mn == INT_MAX)
		mn = sz;
	cout << mn << endl;
	return 0;
}
