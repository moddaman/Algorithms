#include <iostream>
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

int guestChop[1050][5010];
int chopsticks[5010];



int main()
{
	int tC;
	scanf("%d", &tC);
	REP(ca,tC) {
		int k, n;
		scanf("%d %d", &k, &n);
		int i,j;
		for( i=n-1; i>=0; i--) {
			int chop;
			scanf("%d", &chop);
			chopsticks[i] = chop;
		}
		k+=8;
		memset( guestChop, 3000*3000, sizeof(guestChop) );
		
		
		REP(i,n) guestChop[0][i] =0;
		for( i=1; i<=k; i++) {
			for( j=i*3-1; j<n; j++) {
				double dist = chopsticks[j]-chopsticks[j-1];
				double badness = pow (dist,2);
				if(guestChop[i-1][j-2] + badness< guestChop[i][j-1] )
					guestChop[i][j] = guestChop[i-1][j-2]+ badness;
				else {
					guestChop[i][j] = guestChop[i][j-1];
				}
			}
		}
		printf("%d\n", guestChop[k][n-1]);

	}
	return 0;
}