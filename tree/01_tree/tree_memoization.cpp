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

    string nums_str = vector_to_string(nums);

    if (seen_vectors.find(nums_str) != seen_vectors.end()) {
        return seen_vectors[nums_str];
    }

    if (nums.size() == 1) {
        // we found at least 1 good tree
        if (nums[0] == 0) {
            return true;
        }
    }

    for (int i=0; i<nums.size() - 1; i++) {
        // cut out the node with a higher value
        if (abs(nums[i] - nums[i+1]) == 1) {
            int index_to_cut = nums[i] > nums[i+1] ? i : i+1;
            vector<int> new_nums;
            for (int j=0; j<nums.size(); j++) {
                if (j != index_to_cut) {
                    new_nums.push_back(nums[j]);
                }
            }
            if (is_tree_correct(new_nums)) {
                seen_vectors[nums_str] = true;
                return true;
            }
        }
    }

    seen_vectors[nums_str] = false;
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
