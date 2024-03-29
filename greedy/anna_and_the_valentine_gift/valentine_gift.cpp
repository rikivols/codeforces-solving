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


int count_zeros(int num) {
    string num_str = to_string(num);

    int zero_count = 0;
    while (true) {
        if (num % 10 == 0) {
            zero_count++;
            num = num / 10;
        } else {
            break;
        }
    }

    return zero_count;
}

int get_num_of_digits(int num) {
    return to_string(num).size();
}


bool compare_trailing_zeros(int a, int b) {
    return count_zeros(a) > count_zeros(b);
}


bool get_winning_person(vector<int> &nums, int digits_goal) {
    sort(nums.begin(), nums.end(), compare_trailing_zeros);

    int num_of_digits = 0;
    for (int i=0; i<nums.size(); i+=2) {

        // first player reverses the number, getting rid of zeros
        num_of_digits += get_num_of_digits(nums[i]) - count_zeros(nums[i]);

        // second player concatanates that number
        if (i+1 < nums.size()) {
            num_of_digits += get_num_of_digits(nums[i + 1]);
        }

        if (num_of_digits > digits_goal) {
            return true;
        }
    }

    return false;
}


int main() {


    int inputs, n, digits_goal;

    cin >> inputs;

    while (inputs--) {
        vector<int> nums;

        cin >> n;
        cin >> digits_goal;

        for (int i=0; i<n; i++) {
            int temp_num;
            cin >> temp_num;
            nums.push_back(temp_num);
        }

        bool is_sasha_winning = get_winning_person(nums, digits_goal);

        if (is_sasha_winning) {
            cout << "Sasha" << endl;
        } else {
            cout << "Anna" << endl;
        }
    }

    return 0;
}
