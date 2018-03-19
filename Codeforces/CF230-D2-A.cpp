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
#include<fstream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <utility>   // std::pair, std::make_pair
#include <stdlib.h>  //atoi
using namespace std;
typedef long long ll;
const  double PI = 3.141592654;
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
//x = atoi(s.c_str())
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	ll s, x, a, b;
	cin >> s >> x;
	multiset<pair<int, int>>p;
	rep(i, x)
	{
		cin >> a >> b;
		p.insert(make_pair(a, b));
	}
	for (auto e : p)
	{
		if (s > e.first)
			s += e.second;
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
