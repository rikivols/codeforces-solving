
def get_min_jars(lst_left, lst_right, red_num, blue_num, i, j):
    global DP

    if blue_num == red_num:
        return 0

    if (i, j) in DP:
        return DP[(i, j)]

    if i < 0 and j < 0:
        return 0

    if i < 0:
        jam_num = lst_right[j]
        if jam_num == 1:
            DP[(i, j)] = get_min_jars(lst_left, lst_right, red_num-1, blue_num, i, j-1) + 1
        else:
            DP[(i, j)] = get_min_jars(lst_left, lst_right, red_num, blue_num - 1, i, j-1) + 1
        return DP[(i, j)]

    if j < 0:
        jam_num = lst_left[i]
        if jam_num == 1:
            DP[(i, j)] = get_min_jars(lst_left, lst_right, red_num-1, blue_num, i-1, j) + 1
        else:
            DP[(i, j)] = get_min_jars(lst_left, lst_right, red_num, blue_num - 1, i-1, j) + 1

        return DP[(i, j)]

    jam_num_left = lst_left[i]

    if jam_num_left == 1:
        num1 = 1 + get_min_jars(lst_left, lst_right, red_num-1, blue_num, i-1, j)
    else:
        num1 = 1 + get_min_jars(lst_left, lst_right, red_num, blue_num-1, i-1, j)

    jam_num_right = lst_right[j]

    if jam_num_right == 1:
        num2 = 1 + get_min_jars(lst_left, lst_right, red_num-1, blue_num, i, j-1)
    else:
        num2 = 1 + get_min_jars(lst_left, lst_right, red_num, blue_num-1, i, j-1)
    DP[(i, j)] = min(num1, num2)

    return DP[(i, j)]


num1 = int(input())

for i in range(num1):
    n = int(input())
    DP = {}
    jams = input().split(' ')
    jams = [int(i) for i in jams]

    number_of_red = 0
    number_of_blue = 0

    for jam in jams:
        if jam == 1:
            number_of_red += 1
        else:
            number_of_blue += 1

    arr1 = jams[:n]
    arr2 = jams[n:]
    arr2.reverse()

    print(get_min_jars(arr1, arr2, number_of_red, number_of_blue, n-1, n-1))
