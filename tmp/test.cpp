#include<iostream>

using namespace std;

int a(int b)
{
    return b;
}
int a(int b,int c)
{
    return b+c;
}
int main()
{
    a(2);
    a(1,2);

    return 0;
}
