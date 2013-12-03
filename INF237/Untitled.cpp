#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
	
	int x = 1600;
	for(int i = 1; i < 40; i++) {
		x += 1600*12;
		x += x * 0.10;
	}
	printf("%d", x);
}