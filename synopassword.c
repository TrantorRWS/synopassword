#include <stdlib.h> 
#include <time.h> 
#include <stdio.h> 

void main()
{
    struct timeval tvTime;
    struct tm tmOutput;

    gettimeofday(&tvTime, 0);
    localtime_r(&(tvTime.tv_sec), &tmOutput);

    tmOutput.tm_mon += 1;
    printf("password for today is: %x%02d-%02x%02d\n\n",
        tmOutput.tm_mon, tmOutput.tm_mon, tmOutput.tm_mday,
        gcd(tmOutput.tm_mon, tmOutput.tm_mday));
}

int gcd(int a, int b)
{
    return (b?gcd(b,a%b):a);
}
