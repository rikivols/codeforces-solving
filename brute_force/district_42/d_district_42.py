num = int(input())

str_ = ""

for i in range(1, num + 1):
    str_ += str(i)

res = 0
for i in range(1, len(str_)):
    if str_[i-1] + str_[i] == "42":
        res += 1

print(res)
