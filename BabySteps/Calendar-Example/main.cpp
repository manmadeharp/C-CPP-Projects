
#include <map>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    // Months table
    map<int, int> mons = {
        {1,  31},
        {2,  28},
        {3,  31},
        {4,  30},
        {5,  31},
        {6,  30},
        {7,  31},
        {8,  31},
        {9,  30},
        {10, 31},
        {11, 30},
        {12, 31},
    };

    time_t t = time(NULL);   // get time now
    struct tm *now = localtime(&t);

    int day  = now->tm_mday;
    int mon  = now->tm_mon + 1;
    int year = now->tm_year + 1900;

    // Check for leap years
    if (year % 400 == 0 || (year % 4 == 0 && (year % 100 != 0))) {
        mons[2] = 29;
    }

    // Compute the magic number
    year--;
    int st = 1 + year * 365 + year / 4 - year / 100 + year / 400;

    for (int i = 1; i < mon; i++) {
        st += mons[i];
    }

    // Name of the current month
    char buffer[32];
    strftime(buffer, sizeof(buffer), "%B", now);
    string monName(buffer);

    // Month name + year
    char monYear[64];
    sprintf(monYear, "%s %d", buffer, year + 1);

    // Calendar header
    printf("%*s\n%s\n", (int)((monName.size() + 20 + 5) >> 1), monYear, "Su Mo Tu We Th Fr Sa");

    for (int i = 0; i < st % 7; i++) {
        cout << "   ";
    }

    // Printing the days of the month
    for (int i = 1; i <= mons[mon]; i++) {
        printf(i == day ? "\e[7m%2d\e[0m " : "%2d ", i);
        (st + i) % 7 == 0 && i != mons[mon] &&cout << endl;
    }

    cout << endl;

    // Done
    return 0;
}
