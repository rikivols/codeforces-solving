#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;


template <typename T>
void printVector(vector<T> &vec) {
    for (unsigned long long i=0; i<vec.size(); i++) {
        cout << to_string(vec[i]) + " ";
    }
    cout << "\n";
}


void printMap(const std::map<int, std::string>& myMap) {
    for (const auto& pair : myMap) {
        std::cout << pair.first << " : " << pair.second << '\n';
    }
}


void printMap(const std::unordered_map<long long, long long>& myMap) {
    for (const auto& pair : myMap) {
        std::cout << pair.first << " : " << pair.second << '\n';
    }
}


void load_numbers(int inputs1, vector<long long> &nums, unordered_map<long long, long long>& real_positions) {
    long long type_of_operation, operation;

    long long cur_size = 0;

    while (inputs1--) {

        cin >> type_of_operation;
        cin >> operation;

        if (type_of_operation == 1) {
            nums.push_back(operation);
            real_positions[cur_size] = operation;
            cur_size++;
        } else if (type_of_operation == 2) {
            nums.push_back(-operation);
            cur_size *= (operation + 1);
        }
    }
}


int main() {


    long long inputs;

    cin >> inputs;

    while (inputs--) {
        long long inputs1, inputs2, type_of_operation, operation;

        cin >> inputs1;
        cin >> inputs2;
        vector<long long> nums;
        map<long long, long long> indexes;
        unordered_map<long long, long long> real_positions;


        load_numbers(inputs1, nums, real_positions);

        long long query;
        vector<long long> queries;
        vector<pair<long long, int>> query_pairs;

        while (inputs2--) {
            cin >> query;
            queries.push_back(query);
        }

        for (int i = 0; i < queries.size(); ++i) {
            query_pairs.push_back({queries[i], i});
        }

        sort(query_pairs.begin(), query_pairs.end());
        sort(queries.begin(), queries.end());
        vector<long long> cur_vector;

        long long cur_size = 0;
        long long cur_index = 0;
        long long cur_query = 0;
        long long last_result;
        bool is_last = false;
        vector<long long> results(query_pairs.size(), 0);

        for (long long i = 0; i < queries.size(); i++) {

            if (i > 0 and queries[i] == queries[i-1]) {
                results[query_pairs[i].second] = last_result;
                continue;
            }

            cur_query = queries[i];
            bool to_break = false;

            while (true) {

                long long cur_num = nums[cur_index];
                if (cur_num > 0) {
                    cur_size++;

                    if (cur_query == cur_size) {
                        results[query_pairs[i].second] = nums[cur_index];
                        last_result = nums[cur_index];
                        // fix if next query is the same
                        cur_vector.push_back(nums[cur_index]);
                        cur_index++;
                        break;
                    }
                    else {

                        cur_index++;
                    }
                }
                else {
                    long long repetition_times = -cur_num + 1;
                    indexes[cur_size] = repetition_times;

                    if (cur_query <= cur_size * repetition_times) {
                        long long query_reduced = cur_query;

                        long long closest_repetition_times;
                        long long closest_size;

                        while (true) {
                            if (real_positions.find(query_reduced - 1) != real_positions.end()) {
                                results[query_pairs[i].second] = real_positions[query_reduced-1];

                                last_result = real_positions[query_reduced-1];
                                to_break = true;
                                break;
                            }

                            auto it = indexes.lower_bound(query_reduced);
                            if (it == indexes.begin()) {
                                results[query_pairs[i].second] = real_positions[query_reduced-1];

                                last_result = real_positions[query_reduced-1];
                                to_break = true;
                                break;
                            } else if (it == indexes.end() || it->first != query_reduced) {
                                --it;
                            }
                            closest_size = it->first;
                            closest_repetition_times = it->second;

                            query_reduced = query_reduced % closest_size;
                            if (query_reduced == 0) {
                                query_reduced = closest_size;
                            }
                        }
                    } else {
                        cur_size *= repetition_times;
                        cur_index++;
                    }
                }
                if (to_break) {
                    break;
                }
            }
        }

        for (long long i = 0; i < results.size(); i++) {
            if (i == results.size() - 1) {
                cout << results[i] << endl;
            } else {
                cout << results[i] << " ";
            }
        }
    }

    return 0;
}
