#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    int num;
    int n = rand() % 100 + 1;   // btw 1 to 100
    cout << "Enter a number to guess (-1 to exit): ";
    cin >> num;
    while (num != -1)
    {
        if (num == n)
        {
            cout << "Guess is correct" << endl;
        }
        else if (num < n)
        {
            cout << "Guess is low" << endl;
        }
        else if (num > n)
        {
            cout << "Guess is high" << endl;
        }
        cout << "Enter a number to guess (-1 to exit): ";
        cin >> num;
    }
    return 0;
}