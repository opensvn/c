#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

bool cmp_value(int a, int b)
{
    return a >> 2 < b >> 2;
}

void print(int *a, int len)
{
    for (int i = 0; i < len; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[13] = {0};

    srand(time(NULL));
    for (int i = 0; i < 13; ++i)
    {
        a[i] = rand() % 256;
    }
    print(a, 13);

    sort(begin(a), end(a));
    print(a, 13);

    sort(begin(a), end(a), cmp);
    print(a, 13);

    for (int i = 0; i < 13; ++i)
        a[i] >>= 2;
    sort(begin(a), end(a), cmp_value);
    print(a, 13);

    return 0;
}
