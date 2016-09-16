#include <stdio.h>
#include <time.h>

int main()
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = gmtime(&timer);
    printf("difftime: %f\n", difftime(timer, 1473349260));

    strftime(buffer, 26, "%Y%m%dT%H%M%SZ", tm_info);
    puts(buffer);

    return 0;
}
