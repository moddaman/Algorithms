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
#include <iostream>

    
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
	
	int n;
	scanf("%d",&n);
	char str1[250005];
	char str2[500005];
	int overlapp[500005];
	
	REP(i,n) {
		  overlapp[i] = 0;
		  char a;
		  scanf("%c", &a);
		  if(a == '\n'){
	     	 scanf("%c", &a);
		           }
		  str1[i] = a;
		} 
		REP(i,n) {
			  char a;
			  scanf("%c", &a);
			  if(a == '\n'){
		     	 scanf("%c", &a);
			           }
			  str2[i] = a;
		}
	strncpy(str2+n,str2,n);
	int i;
	overlapp[0] = 0;
	overlapp[1] = 0;
	FOR (i,2,n) {
		overlapp[i] = overlapp[i-1]; 
		while(overlapp[i] && str1[overlapp[i]] != str1[i-1])
			overlapp[i] = overlapp[overlapp[i]];
		if (str1[overlapp[i]] == str1[i-1]) 
			overlapp[i]=overlapp[i]+1;

	}
	if (str1[overlapp[i]] == str1[i-1]) 
		overlapp[i]=overlapp[i]+1;
	bool f= false;
	int fin=-1;
	for (int j = 0, overL = 0; j<2*n; ++j) {
		while(overL > 0 && str1[overL] != str2[j]){
			overL = overlapp[overL];
		}
		if (str1[overL] == str2[j] && ++overL == n) {
			overL = overlapp[i];
			fin = j + 1 - n;
			f = true;
		}
		if(f || overL > n) break;
	}
	if(f) printf("%d",fin);
	else printf("-1");
	return 0;
		
		
		
		
		
		
		
		
		
		
		
		
}