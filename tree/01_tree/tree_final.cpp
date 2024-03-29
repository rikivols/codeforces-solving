#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


template <typename T>
void printVector(vector<T> &vec) {
    for (unsigned long i=0; i<vec.size(); i++) {
        cout << to_string(vec[i]) + " ";
    }
    cout << "\n";
}


bool initial_check_of_tree(vector<int> &nums) {
    int num_of_zeros = 0;
    for (int num : nums) {
        if (num == 0) {
            num_of_zeros++;
            if (num_of_zeros > 1) {
                return false;
            }
        }
    }

    return true;
}

void remove_tree_children(vector<int> &tree_path_sums, int new_element) {
    while (true) {
        auto n = tree_path_sums.size();
        if (tree_path_sums.size() > 1 and
            (tree_path_sums[n-1] == tree_path_sums[n-2] or tree_path_sums[n-1] == tree_path_sums[n-2] + 1) and
            new_element < tree_path_sums[n-1]) {
            tree_path_sums.pop_back();
        }
        else {
            break;
        }
    }
}

bool is_tree_correct(vector<int> &nums) {

    // if there are more than 1 zeros, the tree is incorrect
    if (!initial_check_of_tree(nums)) {
        return false;
    }

    vector<int> tree_path_sums;
    tree_path_sums.push_back(nums[0]);

    for (int num: nums) {

        // remove children that we can match with their neighbor, that's 1 less than them
        remove_tree_children(tree_path_sums, num);

        // we have a new path in a tree that we need to pair with its neighbor later
        if (num >= tree_path_sums.back()) {
            tree_path_sums.push_back(num);
        }
        // we can add a new node to the tree and immediately remove the tree_path_sums.back() and
        // its neighbor, only nums[i] will remain
        else if (num + 1 == tree_path_sums.back()) {
            tree_path_sums.back() = num;
        }
        else {
            return false;
        }
    }

    remove_tree_children(tree_path_sums, -1);
    // we have remaining nodes in the tree, we weren't able to match some neighbor nodes
    return tree_path_sums.size() == 1 and tree_path_sums[0] == 0;
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

        if (is_correct) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
