#include <iostream> 
using namespace std;

int main() 
{ 
  // int *p;
  // p = (int *)malloc(20);
  // free(p);
  // cout<<sizeof(p);
  signed char c = 127;
  cout<<(int)c;
  c = c + 8;
  printf("%d", c);
  // cout<<(int)c;
  return 0; 
} 