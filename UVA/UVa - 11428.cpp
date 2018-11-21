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
	ll n;
	bool ok = 0;
	while (cin >> n && n != 0)
	{
		ll x = 1, y = 1;
		ok = 0;
		while (x>=y && x<1000 && y<1000)
		{
			ll ans = pow(x, 3) - pow(y, 3);
			if (ans < n)
				x++;
			else if (ans>n)
				y++;
			else
			{
				cout << x << " " << y << "\n";
				ok = 1;
				break;
			}
		}
	if (!ok)
		cout << "No solution\n";
	}
	return 0;
}
