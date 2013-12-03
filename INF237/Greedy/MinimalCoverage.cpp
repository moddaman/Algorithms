#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <string>
    
#define REP(i,n) for(int _n=(n),i=0; i<_n; ++i)
#define FOR(i,a,b) for(int _b=(b),i=(a); i<= _b; ++i)
#define FORD(i,a,b) for(int _b=(b),i=(a); i>=_b; --i)

#define PB push_back
#define BEG begin()
#define END end()
#define SZ s()
#define MP make_pair
#define F first
#define S second
#define D double
#define LL long long
#define LD long double
#define VI vector<int>

using namespace std;
struct PairComparator 
{
  
bool operator()( pair<int,int> n1, pair<int,double> n2) 
    {  
	

		if(n1.F != n2.F) 
			return n1.F > n2.F;
		else {
			return n1.S < n2.S;
		}
       }
    
};
int main(int argc, char *argv[]) {
	
	priority_queue<pair<int,int> , vector< pair<int,int> > , PairComparator> pq;
	int m;
	vector<pair<int,int> > v;
	int venstre = 0;
	int covered = 0;
	scanf("%d",&m);
	while (true) {
		int le,ri;
		scanf("%d %d", &le, &ri);
		if(le == 0 && ri == 0) break;
		pq.push(MP(le,ri));
	}
	bool flagg = true;
	pair<int,int> pick = MP(-600000,-600000);
	pair<int,int> par = pq.top();
	int pF = par.F;
	while(!pq.empty()) {
		if(pq.top().F > venstre) {
			flagg = false;
			break;
		}
		while(pq.top().F <= venstre && !pq.empty()) {
			pair<int,int> par = pq.top();
			if(par.S > pick.S) pick = par;
			pq.pop();
		}
		venstre = pick.S;
		v.PB(MP(pick.F,pick.S));
		if(pick.S >= m) break;
	}
	if(v.size() == 0 || !flagg || pick.S < m) printf("No solution");
	else {
	printf("%ld\n",v.size());
		REP(i, v.size()) {
			printf("%d %d\n", v[i].F, v[i].S);
		}
	}
return 0;
}