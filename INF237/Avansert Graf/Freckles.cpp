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

struct PairComparator 
{
  bool operator()(pair< int, pair<double,double> > n1,pair< int, pair<double,double> > n2) 
    {  
	if( n1.F < n2.F ) return true;
		return false;
        }
    
};
//pow (7.0,3)

// param = 1024.0;
//  result = sqrt (param);


int main(int argc, char *argv[]) {
	
	priority_queue<pair< double, pair<double,double> >, vector<pair<double, pair<double,double> > > , PairComparator> pq;
	pq.push(MP(2.0, MP(2.0, 3.4)));
	pq.push(MP(3.0, MP(2.0, 3.4)));
	
	int tC;
	scanf("%d", &tC);
	REP(t, tC) {
		int n;
		scanf("%d", &n);
		
		REP(i, n) {
			double x, y;
			scanf("%lf %lf", &x,&y);
			printf(" %f", x);
			printf("  %f", y);

		}
		
	}
	














	
}