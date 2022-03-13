#include <iostream>
#include <time.h>
using namespace std;
int* m = new int[4];
int* q = new int[4];
static int sproba = 0;
int* randNumber()
{
    for (int i = 0; i < 4; i++)
        *(m + i) = rand() % 10;
    return m;
}
int* digits(int n)
{
    for (int i = 3; i >= 0; i--)
    {
        *(q + i) = n % 10;
        n /= 10;
    }
    return q;
}
void Count(int* x, int* y, int n, int* bull, int* cow)
{
    *bull = *cow = 0;
    for (int i = 0; i < n; i++)
        if (*(x + i) == *(y + i))
            (*bull)++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((*(x + i) == *(y + j)) && (i != j))
                (*cow)++;
}
void game(int* r, int* N)
{
    *N = sproba;
    cout << "Input your number: ";
    int number;
    cin >> number;
    int* b = digits(number);
    int bull, cow;
    Count(r, b, 4, &bull, &cow);
    cout << "Bulls = " << bull << ", cows = " << cow << endl;
    sproba++;
    if (bull == 4) cout << "OK!\n";
    else game(r, N);
}
void main()
{
    int m = 0;
    srand(time(NULL));
    int* a = randNumber();
    game(a, &m);
    cout << "Winning in " << m << " moves!\n";
}