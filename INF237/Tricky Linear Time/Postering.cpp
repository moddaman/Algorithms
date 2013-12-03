
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


int a;
int n = 0;
int teller = 0;
scanf("%d",&a);
int tab[a];

REP(i, a) {
	tab[i] = 0;
}

REP(i, a) {
	int b, h;
	scanf("%d %d",&b, &h);
	while(teller >= 0) {
		if(h == tab[teller]) {
				break;
		  }
		else if(h > tab[teller]) {
			teller++;
			tab[teller] = h;
			n+=1;
			break;
		  }  
		else if(h < tab[teller]) {
			tab[teller] = 0;			
			teller--;
			
		 } 
	}

}

printf("\%d", n);

}
			