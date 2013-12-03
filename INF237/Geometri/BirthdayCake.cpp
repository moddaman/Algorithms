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
	#define offset 135000



	using namespace std;
	int n;
	int x[1002];
	int y[1002];

	bool fordeling(int a, int b) {
		int p = 0;
		int m = 0;
		for(int i = 0; i < n*2;i++){
			int res = a*x[i] + b*y[i];
			if(res < 0) m += 1;
			if(res > 0) p += 1;
			if(res == 0) return false;
		}	
		if(p == m) return true;
		else return false;
	}

	void combinations() {
				for(int a = -500; a <= 500;a++){
					for(int b= -500; b <= 500; b++) {
							if(fordeling(a, b)) {
								printf("%d %d\n", a,b);
								return;
							}
						}
					}		
	}


	int main() {
		
		
		while(true) {
			scanf("%d", &n);

			if(n == 0) break; 
				for(int i =0; i<n*2;i++) {
				int x1,y1;
				scanf("%d %d",&x1,&y1);
				x[i] = x1;
				y[i] = y1;
			}
			combinations();

		}
		return 0;
		
	}