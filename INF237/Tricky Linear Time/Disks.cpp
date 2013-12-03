
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


int main(int argc, char *argv[]) {
	
	int sh, ad;
	int min = std::numeric_limits<int>::max();;
	
	scanf("%d %d", &sh, &ad );
	
	sh += 1;
	int a[sh];
	
	FOR(i,1, sh-1) {
		int t;
		scanf("%d", &t);
		if(t < min) {
			a[i] = t;
			min = t;
		} else {
			a[i] = min;
		}
	}

	int hi = sh;
	int mid = 0;
	int st = 0;
	REP(i, ad) {
		int t;
		scanf("%d", &t);
		int lo = 1;
		if(t <= a[lo]) {
			hi--;
		while(hi >= lo) {
			int mid = (lo+hi)/2;
			if(a[mid] > t) {
				lo = mid+1;
			}
			else if (a[mid] < t) {
				hi = mid-1;
			}
			else {
				while(t == a[mid+1] && (mid+1) <= hi) {
					mid++;
					}
				hi = mid;
				break;
				}
			}
		} else {
			hi = 0;
			break;
		  }
	}	
	if(hi < 1) hi = 0;
		printf("%d", hi);	
}
