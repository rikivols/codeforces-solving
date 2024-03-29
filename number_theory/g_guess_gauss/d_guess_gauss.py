
inp = int(input())

result = []
for i in range(1, int((2*inp)**0.5)+1):
    if (2*inp) % i == 0:
        real_difference = (2*inp) // i

        if (i + real_difference - 1) % 2 == 0:
            res1 = (i + real_difference - 1) // 2 - i
            res2 = res1 + i
            if res1 > 0 and res2 > 0:
                if res1 > res2:
                    res1, res2 = res2, res1
                if res1 != res2:
                    result.append((res1, res2))

print(len(result))
for res in result:
    print(res[0], res[1])
