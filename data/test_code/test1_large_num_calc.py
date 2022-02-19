def add(a, b):
    sum_list = [0]

    if len(a) > len(b):
        lc = len(a) - len(b)
        b = '{}{}'.format(r'0' * lc, b)
    elif len(a) < len(b):
        lc = len(b) - len(a)
        a = '{}{}'.format(r'0' * lc, a)

    sum_list = sum_list * len(a)

    str1 = list(a[::-1])

    str2 = list(b[::-1])

    for i, v in enumerate(str1):
        v_add = int(str2[i]) + int(v) + sum_list[i]
        if v_add >= 10:
            m, va = divmod(v_add, 10)
            sum_list[i] = va
            sum_list[i + 1] = m
        else:
            sum_list[i] = v_add

    print(''.join('%s' % vi for vi in sum_list[::-1]))


if __name__ == '__main__':
    n1 = "123456789123456789123456789"
    n2 = "2357324573455698357"
    add(n1, n2)
