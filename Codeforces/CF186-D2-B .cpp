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
#include<unordered_map>
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
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
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
	vector<pair<double, int>>v;
	int n, t1, t2, k;
	cin >> n >> t1 >> t2 >> k;
	rep(i, n)
	{
		int a, b;
		cin >> a >> b;
		double R1 = a*t1; R1 = R1 - (R1*(k / 100.0)); R1 += b*t2*1.0;
		double R2 = b*t1; R2 = R2 - (R2*(k / 100.0)); R2 += a*t2*1.0;
		v.push_back({ max(R1, R2), i + 1 });
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i].first == v[j].first && v[i].second>v[j].second)
				swap(v[i], v[j]);
			else if (v[i].first < v[j].first)
				swap(v[i], v[j]);
		}
	}
	rep(i, n)
		cout << v[i].second << " " << fixed << setprecision(2) << v[i].first << "\n";
	return 0;
}
