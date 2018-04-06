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
	int t;
	cin >> t;
	rep(o, t)
	{
		int n, m, k, e = 0;
		cin >> n >> m >> k;
		for (int i = 1; i <= 3; i++)
		{
			if (k == i)
			{
				cout << "Case " << o + 1 << ": " << i << endl;
				e = 1;
				break;
			}
		}
		if (e)
			continue;
		vector<int>v = { 1, 2, 3 };
		int s = 3;
		vector<int>mx;
		while (s < n)
			v.pb((v[s - 1] + v[s - 2] + v[s - 3]) % m + 1), s++;
		vector<int>ans(k + 1);
		int p1 = 0, p2 = 0, mn = 100000000;
		while (p1 < s && p2 < s)
		{
			if (v[p2] >= 1 && v[p2] <= k)
			{
				ans[v[p2]]++;
				while (*min_element(ans.begin()+1,ans.begin()+k + 1)!=0)
				{
					if (v[p1] >= 1 && v[p1] <= k)
					{
						if (ans[v[p1]] - 1 > 0)
						{
							ans[v[p1]]--, p1++, mn = min(abs(p2 - p1), mn);
						}
						else
							break;
					}
					else
						p1++, mn = min(abs(p2 - p1), mn);
				}
			}
			p2++;
		}
		cout << "Case " << o + 1 << ": ";
		if (mn == 100000000)
			cout << "sequence nai" << endl;
		else
			cout << ++mn << endl;
	}
	return 0;
}
