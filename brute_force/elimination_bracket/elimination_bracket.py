
num = int(input())
str_ = input()

final = 0
brackets_state = 0
is_first = False

for i in str_:
    if i == "(":
        brackets_state += 1
        is_first = True
    elif i == ")":
        if brackets_state > 0:
            final += 2

        brackets_state -= 1
        if brackets_state < 0:
            brackets_state = 0

print(final)
