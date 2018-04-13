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
/*ll n, a[22], tmp[20];
void merge(int l1, int r1, int l2, int r2) {
	for (int i = l1; i <= r2; i++)
		tmp[i] = a[i];

	int idx = l1;
	while (l1 <= r1 && l2 <= r2) {
		if (tmp[l1] <= tmp[l2]) {
			a[idx++] = tmp[l1];
			l1++;
		}
		else {
			a[idx++] = tmp[l2];
			l2++;
		}
	}
	while (l1 <= r1)
		a[idx++] = tmp[l1++];
	while (l2 <= r2)
		a[idx++] = tmp[l2++];
}

void merge_sort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	merge(l, mid, mid + 1, r);
}*/
ll x, y, sol = 10000000000;
ll Search(ll n)
{
	ll l = 1, r = 1000000000, md, mn = LONG_MAX, sum = 0;
	while (l <= r)
	{
		sum = 0;
		md = (l + r) / 2;
		ll f = md, idx = 0;
		while (f / pow(y, idx))
		{
			sum += f / pow(y, idx);
			idx++;
		}
		if (sum == x)
			return md;
		if (sum >= x)
			r = md - 1, sol = min(sol, md);
		else if (sum < x)
			l = md + 1;
	}
	return
		sol;
}
int main()
{
	fast();
	cin >> x >> y;
	ll s = Search(y);
	cout << s << endl;
	return 0;
}
