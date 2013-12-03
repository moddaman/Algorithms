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
int main() {
 
    while(true) {
        
        int n;
        scanf("%d",&n);
        
        if(n == 0)
            break;
        
        char island[n+2][n+2];
        std:queue< pair<int,int> > q;
        
        
        for(int i = 0; i <= n+1; i++) {
            for(int j = 0; j <= n+1; j++) {
                island[i][j] = '.';
            }
        }
        
        for(int i=1; i<=n; i++) {
       		for(int j=1; j<=n; j++) {
                char a;
                scanf("%c", &a);
                if(a == '\n'){
                        scanf("%c", &a);
                }
        island[i][j] = a;
        }
}
        
double max = 0;
double min = 100000000000000000;

for(int i = 1; i <= n; i++) {
	 for(int j = 1; j <= n; j++) {
		if(island[i][j] == 'X') {
		double areal = 0;
		double parameter = 0;
		island[i][j] = '*';	
		std::pair<int, int> p1(i, j);
		q.push(p1);
	while(!q.empty()) {
		        pair<int, int> p2 = q.front();
				q.pop();
				areal+=1;
				int x = p2.F;
				int y = p2.S;
				 if(island[x+1][y] == '.') {
					   parameter += 1;
				 } 	else if(island[x+1][y] == 'X') {
						q.push(make_pair(x+1, y));
				 		island[x+1][y] = '*';
				 }
				 if(island[x][y+1] == '.') {
				 	  parameter += 1;
				 } else if(island[x][y+1] == 'X') {
					 q.push(make_pair(x, y+1));
				 	 island[x][y+1] = '*';
				 }
				 if(island[x-1][y] == '.') {
					 parameter += 1;
				 } else if(island[x-1][y] == 'X') {
			        	 q.push(make_pair(x-1, y));
						    island[x-1][y] = '*';
				 }
				 if(island[x][y-1] == '.') {
				 	 parameter += 1;
				 } else if(island[x][y-1] == 'X') {
					    	 q.push(make_pair(x, y-1));
							 island[x][y-1] = '*';
				 }
			}
			  double ratio =  (parameter / areal);
			     if(ratio > max) 
						max = ratio;
			     if(ratio < min) 
						min = ratio;
		}
	}
 
}
 if(min == 100000000000000000){
	min = 0;
}
	 printf("%f %f ", max,  min);
     printf("\n");
    }
	return 0;
}







