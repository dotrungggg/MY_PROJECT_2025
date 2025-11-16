#include <iostream>
#include <cmath> // For abs() in closestNumber
using namespace std;

bool EvenOrOdd(int n)
{
    return n % 2 == 0;
}

void multiplicationTable(int n, int limit = 10)
{
    cout << "Multiplication Table of " << n << ":\n";
    for (int i = 1; i <= limit; i++)
    {
        cout << n << " x " << i << " = " << n * i << endl;
    }
}

int sumOfNaturals(int n)
{
    return n * (n + 1) / 2;
}

int sumOfSquaresOfNaturals(int n)
{
    return n * (n + 1) * (2 * n + 1) / 6; 
}

void swapNumbers(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int closestNumber(int n, int m)
{
    int q = n / m;
    int n1 = m * q;
    int n2 = (n * m > 0) ? m * (q + 1) : m * (q - 1);

    return (abs(n - n1) < abs(n - n2)) ? n1 : n2;
}

int oppositeFaceOfDice(int n)
{
    return 7 - n;
}

int nthTermAP(int a1, int a2, int n)
{
    return a1 + (n - 1) * (a2 - a1);
}

int main()
{
    cout << "----- Even or Odd -----" << endl;
    cout << "Is 5 even ? : " << (EvenOrOdd(5) ? "True" : "False") << endl;
    cout << "Is 10 even ? : " << (EvenOrOdd(10) ? "True" : "False") << endl;

    cout << "\n----- Multiplication Table -----" << endl;
    multiplicationTable(6, 9);

    cout << "\n----- Sum of First n Natural Numbers ----" << endl;
    cout << "Sum of first 10 naturals : " << sumOfNaturals(10) << endl;

    cout << "\n----- Sum of Squares of First n Natural Numbers ----" << endl;
    cout << "Sum of squares of first 10 naturals : " << sumOfSquaresOfNaturals(10) << endl; 

    cout << "\n----- Swap Two Numbers -----" << endl;
    int x = 5, y = 10;
    cout << "Before swap : x = " << x << ", y = " << y << endl;
    swapNumbers(x, y);
    cout << "After swap : x = " << x << ", y = " << y << endl; 

    cout << "\n----- Closest Number -----" << endl;
    cout << "Closest multiple of 12 to 40 : " << closestNumber(40, 12) << endl;
    cout << "Closest multiple of 13 to 50 : " << closestNumber(50, 13) << endl;

    cout << "\n----- Opposite face of Dice -----" << endl;
    cout << "Opposite face of 1 is : " << oppositeFaceOfDice(1) << endl;
    cout << "Opposite face of 3 is : " << oppositeFaceOfDice(3) << endl;

    cout << "\n----- Nth Term of AP from First Two Terms -----" << endl;
    cout << "5th term of AP starting 2, 5 : " << nthTermAP(2, 5, 5) << endl;
    cout << "10th term of AP starting 3, 7 : " << nthTermAP(3, 7, 10) << endl;
    return 0;
}