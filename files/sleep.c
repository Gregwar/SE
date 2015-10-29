#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

double time_us()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double t = (tv.tv_sec%10000)+(tv.tv_usec/1000000.0);

    return t;
}

int main()
{
    double m = 0.0, M = 0.0;
    while (1) {
        double a = time_us();
        usleep(1000);
        double b = time_us()-a;
        if (m == 0.0) {
            m = M = b;
        } else {
            if (b < m) m = b;
            if (b > M) M = b;
        }
        printf("%g (min: %g, max: %g)\n", b, m, M);
    }
}
