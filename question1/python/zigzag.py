array = [1, 2, 3, 4, 5, 6, 7, 8, 9]

# start with flag True
# if flag is True then expect array[i] > array[i-1]
# else flag is False expect array[i] < array[i -1]
# otherwise swap

flag = True

for i in range(1, len(array)):
    if flag and array[i] < array[i - 1]:
        array[i], array[i - 1] = array[i - 1], array[i]
    elif not flag and array[i] > array[i - 1]:
        array[i], array[i - 1] = array[i - 1], array[i]

    flag = not flag

print(array)
