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
  bool operator()(pair< int, double > n1, pair< int, double>  n2) 
    {  
	
	if( n1.S > n2.S ) return true;
		return false;
        }
    
};



int main() {
	
	int tC;
	scanf("%d", &tC);

	while(tC--) {
		vector< pair<double, double> > noder;
		priority_queue< pair< int, double> , vector< pair<int,double> > , PairComparator> pq;

		int n;
		scanf("%d", &n);
		int visited[n];
		REP(i, n) {
			double x, y;
			scanf("%lf %lf", &x,&y);
			noder.PB(MP(x, y));
			visited[i] = 0;
		}
	
		int visit = 0;
		double dist = 0;
		int no = 0;
		while(true) {
			pair<double, double> p1 = noder.at(no);
			FOR(j,1, (n-1)) {
				if(j != no) {
					pair<double, double> p2 = noder.at(j);
					double res =  sqrt (pow((p1.F - p2.F), 2) + pow( (p1.S - p2.S),2));
					pq.push(MP(j, res));
					}
				}
			pair<int, double> top = pq.top();
			while(visited[top.F] == 1){
					top = pq.top();
					pq.pop();
				}
			dist += top.S;
			visit += 1;
			visited[top.F] = 1;
			no = top.F;
			if(visit == (n-1)) break;
		}
		printf("%.2lf \n",dist);
		if(tC) puts("");
		noder.clear();

	}
	return 0;
}