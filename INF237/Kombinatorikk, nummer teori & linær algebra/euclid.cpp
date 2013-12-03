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
int gc,qua,rem;


std::pair<LL,LL> xgcd(pair<LL,LL> p) {
	if(p.S==0) return MP(1,0);
	else {
		lldiv_t qr = lldiv(p.F, p.S); 
		pair<LL, LL> p2 = xgcd(MP(p.S, qr.rem));
		return MP(p2.S, p2.F-qr.quot*p2.S);
	}
}

int main() {
	LL x,y;
	char c;
		while(scanf("%lld %lld", &x,&y) == 2)  {
			pair<LL,LL> pp = xgcd(MP(x,y));
			printf("%lld %lld %lld\n", pp.F, pp.S, (pp.F*x)+(pp.S*y));
	}
	return 0;
	
}