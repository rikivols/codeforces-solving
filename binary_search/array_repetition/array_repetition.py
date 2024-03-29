
def find_index(last_i, ind: int, sizes: list, known_indexes: dict):
    for i in range(last_i, len(sizes)):
        # print("i:", i)
        if ind <= sizes[i]:

            if ind in known_indexes:
                # print("RES:", known_indexes[ind])
                return known_indexes[ind], i

            j = i
            j -= 1
            ind -= sizes[j]
            # print(ind)

            while ind not in known_indexes:
                ind %= sizes[j]

                if ind == 0:
                    ind = sizes[j]
                j -= 1

                # print(ind, i)

            return known_indexes[ind], i
            # print("RES:", known_indexes[ind])


def store_inputs(doubles):

    max_num = 10**18

    known_indexes = {}
    sizes = []
    cur_index = 0
    end = False
    last_num = 0
    for type_, num in doubles:
        if end:
            return known_indexes, sizes

        if type_ == 1:
            cur_index += 1
            if cur_index > max_num:
                cur_index = max_num + 1
                end = True
            known_indexes[cur_index] = num
            last_num = num
            sizes.append(cur_index)
        elif type_ == 2:
            cur_index *= (num + 1)

    if doubles[-1][0] == 2:
        if cur_index > max_num:
            cur_index = max_num + 1
        sizes.append(cur_index)
        known_indexes[cur_index] = last_num

    # print(known_indexes)
    # print(sizes)
    return known_indexes, sizes


n = int(input())

for _ in range(n):
    commands_num, queries_num = map(int, input().split())
    doubles = []
    for _ in range(commands_num):
        doubles.append(tuple(map(int, input().split())))
    known_indexes, sizes = store_inputs(doubles)

    queries = list(map(int, input().split()))
    queries_idx = []
    for i in range(queries_num):
        queries_idx.append((i, queries[i]))

    queries.sort()
    last_res = -1
    last_i = 0

    results = []
    for i in range(len(queries_idx)):
        if i > 0 and queries_idx[i][1] == queries_idx[i - 1][1]:
            results.append(last_res)

            # print(last_res, end=" " if i != len(queries) - 1 else "\n")
            continue
        res, last_i = find_index(last_i, queries_idx[i][1], sizes, known_indexes)
        last_res = res

        results.append(res)
        # print(res, end=" " if i != len(queries) - 1 else "\n")

    for idx, query_num in queries_idx:
        print(results[idx], end=" " if idx != queries_num - 1 else "\n")