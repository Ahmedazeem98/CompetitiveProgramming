#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <utility> 
#include <stdlib.h>  //atoi
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
//x = atoi(s.c_str())
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	set < pair<int, int>>st;
	pair<int, int>p1;
	pair<int, int>p2;
	int x1, y1, x2, y2, x;
	cin >> p1.first >> p1.second >> p2.first >> p2.second;
	for (int i = min(p1.first, p2.first); i <= max(p1.first, p2.first); i++)
	{
		st.insert({ i, min(p1.second, p2.second) });
		st.insert({ i, max(p1.second, p2.second) });
	}
	for (int i = min(p1.second, p2.second); i <= max(p1.second, p2.second); i++)
	{
		st.insert({ min(p1.first, p2.first), i });
		st.insert({ max(p1.first, p2.first), i });
	}
	cin >> x;
	vector<pair<pair<int, int>, int>>v(x);
	rep(i, x)
	{
		cin >> v[i].first.first >> v[i].first.second >> v[i].second;
	}
	int c = 0;
	for (auto e : st)
	{
		bool test = 0;
		rep(i, vz)
		{
			double dis = sqrt(pow(e.first - v[i].first.first, 2) + pow(e.second - v[i].first.second, 2));
			if (dis <= v[i].second)
			{
				test = 1;
				break;
			}
		}
		if (test)
			c++;
	}
	cout << st.size() - c << endl;
	return 0;
}
