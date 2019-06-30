//Validate an IP Address
#include<bits/stdc++.h>
using namespace std;
bool validDigit(char *ip_str) 
{ 
    while (*ip_str) { 
        if (*ip_str >= '0' && *ip_str <= '9') 
            ++ip_str; 
        else
            return 0; 
    } 
    return 1; 
} 
bool is_valid_ip(char *str) {
    if(str == NULL)
        return 0;

    char *ptr= strtok(str, ".");
    if(ptr == NULL || str[0] == 0 || strlen(ptr) > 3)
        return 0;
    int dots=0, num;
    num= atoi(ptr);
    if(num == 0 && strlen(ptr) >1)
        return 0;

    while(ptr) {
        if(!validDigit(ptr))
            return 0;
    
        num= atoi(ptr);
        if(num >=0 && num <=255) {
            ptr= strtok(NULL, ".");
            if(ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }
    if(dots != 3)
        return 0;
    return 1;
}
int main() 
{ 
    char ip1[] = "0000.0000.0000.0000"; //0
    char ip2[] = "125.16.100.1"; //1
    char ip3[] = "172.16.254.01"; //0
    char ip4[] = "125.512.100.abc"; //0
    is_valid_ip(ip1)? cout<<1<<"\n" : cout<<0<<"\n"; 
    is_valid_ip(ip2)? cout<<1<<"\n" : cout<<0<<"\n";
    is_valid_ip(ip3)? cout<<1<<"\n" : cout<<0<<"\n";
    is_valid_ip(ip4)? cout<<1<<"\n" : cout<<0<<"\n";
    return 0; 
} 