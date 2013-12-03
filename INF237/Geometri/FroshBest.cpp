#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <cstring>
#include <stack>


    
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
//Problem Algrotimen får problemer hvis alle punktene er på en linje.

using namespace std;
int n;

struct PairComparator {
	bool operator() (pair<double, double> p1, pair<double,double> p2){
     	   float diff = atan2l(p1.S,p1.F);
			float sec =  atan2l(p2.S,p2.F);
			if(diff != sec) return diff < sec;
			else {
			 	double res1 =  sqrt (pow((p1.F - 0), 2) + pow( (p1.S - 0),2));
			 	double res2 =  sqrt (pow((p2.F - 0), 2) + pow( (p2.S - 0),2));
				return res1 < res2;
				}				
    }
};

double vectorProduct(pair<double, double> p1,pair<double, double> p2,pair<double, double> p3) {
	
	return (p2.F-p1.F)*(p3.S-p1.S)-(p2.S-p1.S)*(p3.F-p1.F);
	
};

double specialCase() {
	if(n==0) return 0.0;
	 else {
			double x1,y1;
			scanf("%lf %lf", &x1,&y1);
			double tilO = sqrt (pow((x1 -0), 2) + pow( (y1 - 0),2));
	if(n==1) return tilO*2;
	else {
		double x2,y2;
		scanf("%lf %lf", &x2,&y2);
		double tila = sqrt (pow((x2 - x1), 2) + pow( (y2 - y1),2));
		double tilO2 = sqrt (pow((x2 -0), 2) + pow( (y2 - 0),2));
		return tilO+tila+tilO2;
		}
 	}
};	


vector<pair<double, double> > convexHull(){
	vector<pair<double,double> > A;
	int lowest = 0;
		REP(i, n) {
			double x, y;
			scanf("%lf %lf", &x,&y);
			A.PB(MP(x,y));
			if(y < A[lowest].S && x < A[lowest].F)
				lowest = i;
		}
		pair<double, double> start = A[lowest];
		REP(i, n) {
					printf(" %d %.2lf %.2lf \n", i, A[i].F, A[i].S);
				}
				printf("\n");
		A.erase(A.begin() + lowest);
		sort(A.begin(), A.end(), PairComparator());
		REP(i, n) {
			printf(" %d %.2lf %.2lf \n", i, A[i].F, A[i].S);
		}
			vector<pair<double,double> > hull;
			A.PB(start);
			hull.PB(start);
			REP(i, A.size()) {
				
				while(hull.size() > 1 && vectorProduct(A[i], hull[hull.size()-1],hull[hull.size()-2]) >= 0) {
					hull.pop_back();
				}
				hull.PB(A[i]);
			}

		return hull;
}



int main() {
	//Når alle er på linje
	int tC;
	scanf("%d", &tC);
	REP(t, tC) {
		scanf("%d", &n);
		double total = 0.0;
		if(n <= 2) { //HUSK spesial case når, froshes <= 2
			total = specialCase();
		}
		else {
			vector<pair<double,double> > outer = convexHull(); 
			double dist = 0.0;
			double minste = 3000*3000*3000;
			REP(i,outer.size()-2) { //Hvis hele perimeter: må man ta me hele size.
				double res = sqrt (pow((outer[i].F - outer[i+1].F), 2) + pow( (outer[i].S - outer[i+1].S),2));
				dist +=  res;
			}	
			double tilOrigo1 = sqrt (pow((outer[0].F -0), 2) + pow( (outer[0].S - 0),2));
			double tilOrigo2 = sqrt (pow((outer[outer.size()-1].F -0), 2) + pow( (outer[outer.size()-1].S - 0),2));
			total = dist+(tilOrigo1 +tilOrigo2);
		  }
		printf("%.2lf\n", total+2);
		if(t < tC-1)printf("\n");
	}	
	return 0;
}
