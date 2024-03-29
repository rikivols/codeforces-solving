#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


template <typename T>
void printVector(vector<T> &vec) {
    for (unsigned long i=0; i<vec.size(); i++) {
        cout << to_string(vec[i]) + " ";
    }
    cout << "\n";
}


long long get_counting(vector<long long> &nums, long long n) {
    vector<long long> frequency(n+2, 0);

    for (long long num : nums) {
        frequency[num]++;
    }

    vector<long long> numbers_less_than(n+2, 0);

    for (long long i=n; i>0; i--) {
        long long divisors = 0;
        for (long long j=i; j<=n; j+=i) {
            divisors += frequency[j];
        }
        numbers_less_than[i] = divisors * (divisors - 1) / 2;
    }

    for (long long i=n; i>0; i--) {
        for (long long j=i*2; j<=n; j+=i) {
            numbers_less_than[i] -= numbers_less_than[j];
        }
    }

    for (long long i=0; i<=n; i++) {
        if (frequency[i] > 0) {
            for (long long j=i; j<=n; j+=i) {
                numbers_less_than[j] = 0;
            }
        }
    }

    long long sum = 0;

    for (long long i : numbers_less_than) {
        sum += i;
    }

    return sum;
}


int main() {


    long long inputs, n;

    cin >> inputs;

    while (inputs--) {
        vector<long long> nums;

        cin >> n;

        for (long long i=0; i<n; i++) {
            long long temp_num;
            cin >> temp_num;
            nums.push_back(temp_num);
        }

        long long good_pairs = get_counting(nums, n);

        cout << good_pairs << endl;
    }

    return 0;
}
