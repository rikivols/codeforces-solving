#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

ull find_index(ull &last_i, ull ind, const vector<ull>& sizes, const unordered_map<ull, ull>& known_indexes) {
    for (ull i=last_i; i<sizes.size(); i++) {
        if (ind <= sizes[i]) {
            if (known_indexes.count(ind)) {
                last_i = i;
                return known_indexes.at(ind);
            }

            ull j = i;
            j -= 1;
            ind -= sizes[j];
            while (!known_indexes.count(ind)) {
                ind %= sizes[j];
                if (ind == 0) {
                    ind = sizes[j];
                }
                j -= 1;
            }
            last_i = i;
            return known_indexes.at(ind);
        }
    }
    return 1;
}


ull max_num = 10e18;


void store_inputs(const vector<pair<ull, ull>>& doubles, unordered_map<ull, ull>& known_indexes, vector<ull>& sizes) {
    ull cur_index = 0, last_num = 0;
    bool end = false;
    for (const auto& [type_, num] : doubles) {
        if (end) {
            return;
        }

        if (type_ == 1) {
            cur_index += 1;
            if (cur_index > max_num) {
                cur_index = cur_index + 1;
                end = true;
            }
            known_indexes[cur_index] = num;
            last_num = num;
            sizes.push_back(cur_index);
        } else if (type_ == 2) {
            if (cur_index > numeric_limits<ull>::max() / (num + 1)) {
                cur_index = max_num + 1;
                sizes.push_back(cur_index);
                known_indexes[cur_index] = last_num;
                return;
            }
            cur_index *= (num + 1);
        }
    }

    if (doubles.back().first == 2) {
        if (cur_index > max_num) {
            cur_index = cur_index + 1;
        }
        sizes.push_back(cur_index);
        known_indexes[cur_index] = last_num;
    }
}

int main() {
    ull n;
    cin >> n;

    while (n--) {
        ull commands_num, queries_num;
        cin >> commands_num >> queries_num;
        vector<pair<ull, ull>> doubles;
        for (ull i=0; i<commands_num; ++i) {
            ull type, num;
            cin >> type >> num;
            doubles.emplace_back(type, num);
        }

        unordered_map<ull, ull> known_indexes;
        vector<ull> sizes;
        store_inputs(doubles, known_indexes, sizes);

        vector<pair<ull, ull>> query_pairs;
        ull query;

        for(ull i=0; i<queries_num;i++) {
            cin >> query;
            query_pairs.emplace_back(query, i);
        }
        sort(query_pairs.begin(), query_pairs.end());
//        for (const auto& p : query_pairs) {
//            cout << "(" << p.first << ", " << p.second << ")" << endl;
//        }
        vector<ull> results;
        ull last_res = 0;
        ull last_i = 0;

        for (ull i=0; i<query_pairs.size(); i++) {
            if (i > 0 and query_pairs[i].first == query_pairs[i-1].first) {
                query_pairs[i].first = last_res;
                continue;
            }
//            cout << "first: " << query_pairs[i].first << " ";
            ull res = find_index(last_i, query_pairs[i].first, sizes, known_indexes);
//            cout << "res: " << query_pairs[i].first << " ";
            query_pairs[i].first = res;

            last_res = res;
        }
        sort(query_pairs.begin(), query_pairs.end(), [](const pair<ull, ull>& a, const pair<ull, ull>& b) {
            return a.second < b.second;
        });
        for (ull i=0; i<query_pairs.size(); i++) {
            cout << query_pairs[i].first;
            if (i != queries_num - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

