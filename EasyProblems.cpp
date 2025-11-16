#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    n = abs(n);

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int reverseDigits(int n)
{
    int rev = 0, sign = (n < 0) ? -1 : 1;
    n = abs(n);

    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return rev * sign;
}

bool isPrime(int n)
{   
    if (n <= 1) 
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i*i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

bool isPower(int x, int y)
{
    if (x == 1)
    {
        return y == 1;
    }

    ll pow = 1;

    while (pow <= y)
    {
        pow *= y;
    }

    return pow == y;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((pow((x2 - x2), 2)) + pow((y2 - y1), 2)); 
}

bool isValidTriangle(int a, int b, int c)
{
    return (a + b > c) && (b + c > a) && (c + a > b);
}

bool doOverlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if (x1 >= x4 || x3 >= x2)
    {
        return false;
    }
    if (y1 >= y4 || y3 >= y2)
    {
        return false;
    }

    return true;
}

ll factorial(int n)
{
    ll fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int pairCubeCount(int n)
{
    int count = 0;

    for (int a = 1; a*a*a < n; a++)
    {
        int b_cube = n - a*a*a;
        int b = cbrt(b_cube);

        if (b*b*b == b_cube)
        {
            count++;
        }
    }

    return count;
}

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

bool isPerfect(int n)
{
    if (n <= 1)
    {
        return false;
    }

    int sum = 1;

    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;

            if (i*i != n)
            {
                sum += n / i;
            }
        }
    }

    return sum == n;
}

void addFraction(int num1, int den1, int num2, int den2)
{
    int den3 = LCM(den1, den2);
    int num3 = num1 * (den3 / den1) + num2 * (den3 / den2);
    int common = GCD(num3, den3);
    cout << num3 / common << "/" << den3 / common << endl;
}

string dayOfWeek(int d, int m, int y)
{
    string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    if (m < 3)
    {
        m += 12;
        y--;
    }

    int h = (d + (13 * (m + 1)) / 5 + y*y / 4 - y / 100 + y / 400) % 7;

    return days[h];
}

ll fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    ll a = 0, b = 1;

    for (int i = 2; i <= n; i++)
    {
        ll c = a + b;
        a = b;
        b = c;
    }

    return b;
}

string decToBinaray(int n)
{
    if (n == 0)
    {
        return "0";
    }

    string binary = "";

    while (n > 0)
    {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }

    return binary;
}

int triangularNumber(int n)
{
    return n * (n + 1) / 2;
}

bool isArmstrong(int n)
{
    int original = n, sum = 0, digits = 0;
    int temp = n;

    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    temp = n;
    
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

bool isPalindrome(int n)
{
    if (n < 0)
    {
        return false;
    }

    return n = reverseDigits(n);
}

int digitRoot(int n)
{
    while (n >= 10)
    {
        n = sumOfDigits(n);
    }

    return n;
}

int main()
{
    cout << "Sum of digits of 3456 : " << sumOfDigits(3456) << endl;

    cout << "Reverse of 3456 : " << reverseDigits(3456) << endl;

    cout << "Is 16 prime ? : " << (isPrime(16) ? "Yes" : "No") << endl;

    cout << "Is 16 a power of 2 ? : " << (isPower(2, 16) ? "Yes" : "No") << endl;

    cout << "Distance between (0,1) and (2,4) : " << distance(0, 1, 2, 4) << endl;

    cout << "Do rectangles (0, 0, 2, 2) and (1, 1, 3, 3) overlap ? : " << (doOverlap(0, 0, 2, 2, 1, 1, 3, 3) ? "Yes" : "No") << endl;

    cout << "Factorial of 5 : " << factorial(5) << endl;

    cout << "Number of pairs whose cube sum is 9 : " << pairCubeCount(9) << endl;

    cout << "GCD of 16 and 20 : " << GCD(20, 16) << endl;

    cout << "LCM of 10 and 14 : " << LCM(10, 14) << endl;

    cout << "Is 496 a perfect number ? : " << (isPerfect(496) ? "Yes" : "No") << endl;

    cout << "3/4 + 5/6 = "; 
    addFraction(3, 4, 5, 6);

    cout << "Day of week for 16/11/2025 : " << dayOfWeek(16, 11, 2025) << endl;

    cout << "16th Fibonacci number : " << fibonacci(16) << endl;

    cout << "Binary of 16 : " << decToBinaray(16) << endl;

    cout << "10th triangular number : " << triangularNumber(10) << endl;

    cout << "Is 370 an Armstrong number ? : " << (isArmstrong(370) ? "Yes" : "No") << endl;

    cout << "Is 1010 a palindrome ? : " << (isPalindrome(1010) ? "Yes" : "No") << endl;

    cout << "Digit root of 16 : " << digitRoot(16) << endl;

    return 0;
}