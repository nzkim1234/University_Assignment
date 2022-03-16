from sys import stdin
from copy import deepcopy

# 짝수 패러티 사용
print("해밍코드로 변환시킬 데이터를 입력하시오.")

bits = list(map(int, map(str, stdin.readline().strip())))
original_bits = deepcopy(bits)
len_parity_bit = 0

for i in range(int(1e9)):
    if 2**i - 1 >= i + len(bits):
        len_parity_bit = i
        break

for i in range(len_parity_bit):
    bits.insert(pow(2, i) - 1, 0)

for i in range(len_parity_bit):
    check_range = pow(2, i)
    start = check_range - 1
    count_1 = 0
    count = 0
    toggle = True

    for k in range(start, len(bits)):
        if count == check_range:
            count = 0
            toggle = not toggle
        if toggle:
            if bits[k] == 1:
                count_1 += 1
        count += 1

    if count_1 % 2 == 0:
        bits[start] = 0
    else:
        bits[start] = 1

print("입력된 데이터: "+ "".join(map(str,original_bits)))
print("해밍코드: " + "".join(map(str,bits)))