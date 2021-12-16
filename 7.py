line1 = input()
line2 = input()
i = 0
while line2[i:] + line2[:i] != line1:
    i = line2.find(line1[0], i + 1)
print(i)