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
int dx[] = { 0, 0, -1, 1, -1, 1, -1,1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1 ,-1};
int main()
{
	fast();
	map<char, int>mp;
	string s;
	cin >> s;
	for (char i = 'a'; i <= 'z'; i++)
	{
		int val;
		cin >> val;
		mp[i] = val;
	}
	if (count(all(s), '?') == sz)
	{
		cout << 0 << endl;
		rep(i, sz)
			cout << 'a';
		cout << endl;
		return 0;
	}
	string ss;
	int j = 0;
	if (!isalpha(s[j]) && j < sz)
	{
		int c = 0;
		while (!isalpha(s[j]) && j < sz)
			j++;
		rep(i, j)
			s[i] = s[j];
	}
	ll sum = 0;
	for (int i = 0; i < sz; i++)
	{
		if (isalpha(s[i]) && isupper(s[i]))
			s[i] = tolower(s[i]);
		int b = -1, e = -1;
		string ans;
		int n = 0;
		if (i < sz && s[i] == '?')
		{
			b = i;
			while (s[i] == '?')
				n++, i++;
			if (i < sz)
				e = i - 1;
		}
		if (n)
		{
			if (b - 1 >= 0 && e + 1 < sz && b != -1 && e != -1)
			{
				ll mn = LLONG_MAX;
				char h;
				for (char i = 'a'; i <= 'z'; i++)
				{
					ll sum1 = 0;
					ans += s[b - 1];
					rep(j, n)
						ans += i;
					ans += s[e + 1];
					rep(j, n + 1)
					{
						sum1 += abs(mp[ans[j]] - mp[ans[j + 1]]);
					}
					if (sum1 < mn)
						mn = sum1, h = i;
					ans = "";
				}
				for (int i = b; i <= e; i++)
					s[i] = h;
			}
			else if (b - 1 >= 0 && e == -1 )
			{
				for (int i = b; s[i] == '?'; i++)
					s[i] = s[b - 1];
			}
		}
	}
	for (int i = 0; i < sz - 1; i++)
		sum += abs(mp[s[i]] - mp[s[i + 1]]);
	cout << sum << endl;
	cout << s << endl;
	return 0;
}
