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
#include <unordered_map>
#include <stdlib.h>	
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
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)

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
// atoll(s.c_str()) for ll , atoi fotr int 
int main()
{
	fast();
	int r1, p1, p2, s, a, b;
	vector<int>x, y, z;
	cin >> r1;
	rep(i, r1)
	{
		cin >> s;
		x.push_back(s);
	}
	cin >> p1;
	rep(i, p1)
	{
		cin >> s;
		y.push_back(s);
	}
	cin >> p2;
	rep(i, p2)
	{
		cin >> s;
		z.push_back(s);
	}
	cin >> a >> b;
	int mx_r1 = *max_element(allv(x)), mn_p1 = *max_element(allv(y));
	int mn_p2 = *min_element(allv(z));
	double r2 = (1.0*b*mn_p1 * mx_r1 * mx_r1) / ((1.0*a*mn_p2) + (1.0*b*mn_p1));
	r2 = sqrt(r2);
	cout << fixed << setprecision(12) << r2;
	return 0;
}
