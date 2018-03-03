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
#include <queue>
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
//void file()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//}
int main()
{
	fast();
	int x;
	cin >> x;
	map<int, vector<int>>mp;
	rep(i, x)
	{
		int a;
		cin >> a;
		mp[a].pb(i + 1);
	}
	vector<pair<int, int>>v;
	for (auto e : mp)
	{
		if (e.second.size() == 1)
			v.push_back(make_pair(e.first, 0));
		else
		{
			set<int>st;
			rep(i, e.second.size() - 1)
			{
				st.insert(e.second[i + 1] - e.second[i]);
			}
			if (st.size() == 1)
				v.push_back(make_pair(e.first, *st.begin()));
		}
	}
	cout << v.size() << endl;
	rep(i, vz)
		cout << v[i].first << " " << v[i].second << endl;
	return 0;
}
