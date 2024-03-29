#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;


template <typename T>
void printVector(vector<T> &vec) {
    for (unsigned long i=0; i<vec.size(); i++) {
        cout << to_string(vec[i]) + " ";
    }
    cout << "\n";
}


void build_frequency_table(vector<int> &nums, map<int, unordered_set<int>> &frequency) {
    for (int i=0; i<nums.size(); i++) {
        int key = nums[i];
        if (frequency.find(key) == frequency.end()) {
            frequency[key] = {i};
        } else {
            frequency[key].insert(i);
        }
    }
}

/*
 * Improved idea from quadratic solution. Quadratic solution was finding the maximum
 * value and removing it if at least one of its neighbors was 1 less than it (removing the nodes)
 * if there was no such occurrence, the tree didn't exist, if we ended up with a singular
 * element, whose value was 0, the tree existed.
 *
 * This solution is a bit more optimized, it uses a map to store the frequency of each value.
 * We're also using the index_shifts, telling us how many elements to the right and to the
 * left to shift by, removing the need to erase elements from the vector.
 */
bool is_tree_correct(vector<int> &nums, map<int, unordered_set<int>> &frequency) {

    vector<pair<int, int>> index_shifts(nums.size(), {0, 0});

    for (auto it = frequency.rbegin(); it != frequency.rend(); ++it) {
        int max_value = it->first;
        unordered_set<int> indexes = it->second;

        // this means that we deleted all the tree's nodes, and we only have the root,
        // which is 0, this means that the tree is correct.
        if (indexes.size() == 1 and max_value == 0) {
            return true;
        }

        while (!indexes.empty()) {
            bool was_change = false;

            for (auto index: indexes) {
                int left_index = index + index_shifts[index].first;
                left_index -= 1;
                int right_index = index + index_shifts[index].second + 1;

                // we'll be deleting an index
                if ((left_index >= 0 and abs(nums[left_index] - max_value) == 1) or
                    (right_index < nums.size() and abs(nums[right_index] - max_value) == 1)) {

                    if (left_index >= 0) {
                        index_shifts[left_index].second += index_shifts[index].second + 1;
                    }
                    if (right_index < nums.size()) {
                        index_shifts[right_index].first -= index_shifts[index].first;
                        index_shifts[right_index].first -= 1;
                    }

                    indexes.erase(index);
                    was_change = true;
                    break;
                }
            }

            if (!was_change) {
                return false;
            }

        }
    }

    return false;
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

        map<int, unordered_set<int>> frequency;

        build_frequency_table(nums, frequency);
        bool is_correct = is_tree_correct(nums, frequency);

        if (is_correct) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
