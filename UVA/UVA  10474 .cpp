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
ll n, a[22], tmp[20];
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
}
int main()
{
	fast();
	int x, y, t = 1;
	while (cin >> x >> y && x && y)
	{
		cout << "CASE# " << t++ << ":" << endl;
		vector<int>v(x);
		vector<int>::iterator it;
		rep(i, x)
			cin >> v[i];
		sort(allv(v));
		rep(i, y)
		{
			int a;
			cin >> a;
			it = lower_bound(allv(v), a);
			if (*it == a)
				cout << a << " found at " << it - v.begin() + 1 << endl;
			else
				cout << a << " not found" << endl;
		}
	}
	return 0;
}
