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
int main()
{
	fast();
	int x, y, a;
	cin >> x;
	set<int>st;
	rep(i, x)
		cin >> a, st.insert(a);
	vector<int>v(st.begin(),st.end());
	vector<int>::iterator it;
	int m = st.size();
	cin >> y;
	rep(i, y)
	{
		cin >> a;
		it = lower_bound(allv(v), a);
		int idx = it - v.begin();
		if (idx == m)
		{
			cout << 1 << "\n";
			continue;
		}
		if (a == v[idx])
			cout << m - idx << "\n";
		else
		{
			if (idx == 0)
				cout << m + 1 << "\n";
			else
			{
				idx--; 
				cout << m - idx << "\n";
			}
		}
	}
	return 0;
}
