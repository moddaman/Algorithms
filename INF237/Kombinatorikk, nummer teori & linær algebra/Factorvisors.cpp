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
//http://answers.yahoo.com/question/index?qid=20110726111755AA9Owqq
using namespace std;
vector< pair <LL,LL > > v;


void finnPrimFaktorer(long num) {
        LL n = num;
		LL fo = -1;
        while (n % 2 == 0) {
            if(2 == fo)
            	v[v.size()-1] = MP(v[v.size()-1].F, v[v.size()-1].S +1);
			else {
				v.PB(MP(2,1));
			}
			fo = 2;
            n = n / 2;
        }
       	LL sqrtn = sqrt(n) + 1;
        LL i = 3;
        while (i < sqrtn) {
            if (n % i == 0) {
                  if(i == fo)
            			v[v.size()-1] = MP(v[v.size()-1].F, v[v.size()-1].S +1);
					else {
						v.PB(MP(i,1));
					}
					fo = i;
                	n = n / i;
            } else {
                i = i + 2;
            }
        }
        if (n > 1) {
            if(n == fo)
            	v[v.size()-1] = MP(v[v.size()-1].F, v[v.size()-1].S +1);
			else 
				v.PB(MP(n,1));
			}
    }


LL nPrimfaktorer(LL n, LL p)
{
    LL res = 0;
    for (LL nP = p ; nP <= n ; nP *= p)
        res += n/nP;
    return res;
}


int main() {
	LL n,m;
	while (scanf("%lld %lld",&n,&m)!=EOF) {
	if(m == 0) {
		printf("%lld does not divide %lld!\n", m,n);
		continue;
	}
	if(n > m) {
			printf("%lld divides %lld!\n",m,n);
			continue;
		}
	bool flagg = true;
	finnPrimFaktorer(m);
	REP(i, v.size()) {
		if(nPrimfaktorer(n, v[i].F) < v[i].S) {
			flagg = false;
			break;
		}
	}
	if(flagg) printf("%lld divides %lld!\n",m,n); 
	else printf("%lld does not divide %lld!\n", m,n); 
	v.clear();
	}
	return 0;
}