
def divisible_pairs(arr_inp, x, y):

    MODULOS = {}
    result = 0

    # calculate modulo occurrences
    for arr_value in arr_inp:

        mod1 = arr_value % x
        mod2 = arr_value % y

        to_find1 = 0 if mod1 == 0 else x - mod1

        if (to_find1, mod2) in MODULOS:
            result += MODULOS[(to_find1, mod2)]

        if (mod1, mod2) not in MODULOS:
            MODULOS[(mod1, mod2)] = 0
        MODULOS[(mod1, mod2)] += 1

    return result


if __name__ == "__main__":

    n1 = int(input())
    for _ in range(n1):
        n, x, y = map(int, input().split())
        inp_arr = list(map(int, input().split()))
        result = divisible_pairs(inp_arr, x, y)
        print(result)
