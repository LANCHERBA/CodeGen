# store each time step's calculation result.
sum_list = [0]

a = "87"

b = "345"

# zero fill at front
if len(a) > len(b):
    lc = len(a) - len(b)
    b = '{}{}'.format(r'0' * lc, b)
elif len(a) < len(b):
    lc = len(b) - len(a)
    a = '{}{}'.format(r'0' * lc, a)

# initialize sum_list according to the length of input (fill with zero)
sum_list = sum_list * len(a)

# flip all the elements in list a,b
str1 = list(a[::-1])

str2 = list(b[::-1])

# digit-based addition & carry-over
for i, v in enumerate(str1):
    # sum_list[i] is the carry bit，so add it every time
    v_add = int(str2[i]) + int(v) + sum_list[i]
    if v_add >= 10:
        m, va = divmod(v_add, 10)
        sum_list[i] = va
        sum_list[i + 1] = m
    else:
        # no carry bit needed
        sum_list[i] = v_add

# translate to string
print(''.join('%s'% vi for vi in sum_list[::-1]))
