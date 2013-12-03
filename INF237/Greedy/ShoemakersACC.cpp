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
  bool operator()( pair<int,double> n1, pair<int,double> n2) 
    {  
		if(n1.S != n2.S) 
			return n1.S < n2.S;
		else {
			return n1.F > n2.F;
		}
        }
    
};
int main(int argc, char *argv[]) {
	
	int tC;
	scanf("%d", &tC);
	REP(k,tC) {
		priority_queue<pair<int,double> , vector< pair<int,double> > , PairComparator> pq;
		int n;
		scanf("%d", &n);
		REP(i,n){
			double days,cost;
			scanf("%lf %lf", &days, &cost);
			double total = cost / days;
			pq.push(MP(i+1, total));
		}
		int teller  = 0;
		while(!pq.empty()) {
			if(teller > 0) 	printf(" ");
			pair<int, double> pa = pq.top();
			pq.pop();
			printf("%d",pa.F);
			teller += 1;
		}
		printf("\n");
		if(k < tC-1)
		printf("\n");
	
	}
	return 0;	

}