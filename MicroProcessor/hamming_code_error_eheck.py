from sys import stdin

# 짝수 패러티 사용
print("해밍코드를 입력하시오.")

bits = list(map(int, map(str, stdin.readline().strip())))
len_parity_bit = 0
parity_bit = []
err = False

while pow(2, len_parity_bit) < len(bits):
    len_parity_bit += 1

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

    parity_bit.append(count_1 % 2)

    if count_1 % 2 != 0:
        err = True

print("입력된 해밍코드: " + "".join(map(str,bits)))
if err:
    parity_bit.reverse()
    err_bit = int("0b" + "".join(map(str,parity_bit)),2)
    if bits[err_bit - 1] == 1:
        bits[err_bit - 1] = 0
    else:
        bits[err_bit - 1] = 1
    print(str(err_bit) + "번째 비트에 에러 발생. 수정된 코드: " + "".join(map(str, bits)))
else:
    print('에러없음')