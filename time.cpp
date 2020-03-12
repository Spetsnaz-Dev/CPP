#include <bits/stdc++.h> 
using namespace std; 
// A sample function whose time taken to be measured 
void fun() 
{ 
	for (int i=0; i<10; i++) 
	{ 
	} 
} 

int main() 
{ 
	/* clock_t clock(void) returns the number of clock ticks 
	elapsed since the program was launched.To get the number 
	of seconds used by the CPU, you will need to divide by 
	CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical 
	32 bit system. */
	clock_t start, end; 

	start = clock(); 

	fun(); 
	
    end = clock(); 
    
	// Calculating total time taken by the program. 
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	cout << "Time taken by program is : " << fixed 
		<< time_taken << setprecision(5); 
	cout << " sec " << endl; 
	return 0; 
} 
