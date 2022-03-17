from collections import deque
from sys import stdin

print("비트열을 입력하시오.")
bits = list(map(int, map(str, stdin.readline().strip())))

fcs_msb = deque([0])
fcs_rest = deque([0] * 2)
print("입력된 비트열: " + "".join(map(str, bits)))
print("".join(map(str, fcs_msb + fcs_rest)))

for i in bits:
    if fcs_msb.popleft() != i:
        data_1 = 1
    else:
        data_1 = 0
    
    if fcs_rest.popleft() != data_1:
        data_2 = 1
    else:
        data_2 = 0

    fcs_msb.append(data_2)
    fcs_rest.append(data_1)

    print("".join(map(str, fcs_msb + fcs_rest)))

print("FCS: " + "".join(map(str, fcs_msb + fcs_rest)))