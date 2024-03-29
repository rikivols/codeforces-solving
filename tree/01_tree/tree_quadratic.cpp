#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;


template <typename T>
void printVector(vector<T> &vec) {
    for (unsigned long i=0; i<vec.size(); i++) {
        cout << to_string(vec[i]) + " ";
    }
    cout << "\n";
}

string vector_to_string(const vector<int>& vec) {
    ostringstream oss;
    for (const auto& val : vec) {
        oss << val << ' ';
    }
    return oss.str();
}

unordered_map<string, bool> seen_vectors;

bool is_tree_correct(vector<int> &nums) {

    while (true) {
        if (nums.size() == 1) {
            // we found at least 1 good tree
            if (nums[0] == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        vector<int> max_value_index;
        int max_value = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_value) {
                max_value_index.push_back(i);
            }
        }

        bool was_change = false;
        int index_decreaser = 0;

        for (auto i: max_value_index) {
            i -= index_decreaser;
            if (i < nums.size() - 1 and abs(nums[i] - nums[i + 1]) == 1) {
                nums.erase(nums.begin() + i);
                was_change = true;
                index_decreaser += 1;
            }
            else if (i > 0 and abs(nums[i] - nums[i - 1]) == 1) {
                nums.erase(nums.begin() + i);
                was_change = true;
                index_decreaser += 1;
            }
        }
        if (not was_change) {
            return false;
        }
    }
}


int main() {


    int inputs, n;

    cin >> inputs;

    while (inputs--) {
        vector<int> nums;

        cin >> n;

        for (int i=0; i<n; i++) {
            int temp_num;
            cin >> temp_num;
            nums.push_back(temp_num);
        }

        bool is_correct = is_tree_correct(nums);

        seen_vectors.clear();
        if (is_correct) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
