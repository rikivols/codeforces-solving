#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


long long calculatePhi(long long inputNumber)
{

    long long final = inputNumber;

    if (inputNumber < 1) {
        return 0;
    }

    if (inputNumber == 1) {
        return 1;
    }

    for(long long i=2; i*i <= inputNumber; i++)
    {

        if (inputNumber % i == 0)  // is i prime?
        {

            while (inputNumber % i == 0) {
                inputNumber /= i;
            }

            long long partialResult = final / i;

            final -= partialResult;
        }
    }

    long long partialResult = final / inputNumber;

    if (inputNumber > 1) {
        final -= partialResult;
    }

    return final;
}


long long calculateResult(long long number, long long k) {

    k = (k + 1) / 2;
    while (true) {
        if (k > 0) {
            number = calculatePhi(number);
            k--;
        }
        else {
            return number;
        }

        if (number <= 1) {
            return number;
        }
    }
}

int main() {
    long long n, k;

    cin >> n >> k;

    cout << calculateResult(n, k) % 1000000007 << endl;

    return 0;
}