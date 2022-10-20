import time
from random import randint as ri

# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


def linear_search(value, n_list):
    i = 0
    while True:
        if i >= n:
            break
        if n_list[i] == value:
            break
        i = i + 1
    return i


def binary_search(value, ll):
    low = 0
    high = n - 1
    while low <= high:
        mid = int((low + high) / 2)
        if ll[mid] > value:
            high = mid - 1
        elif ll[mid] < value:
            low = mid + 1
        else:
            return mid
    return -1


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('User')
    li = []
    n = int(input('Enter no of data: '))
    for x in range(n):
        li.append(ri(0, 1000))
    li.sort()
    # print(li)
    # print('not found' if linear_search(int(input("What to search: ")), li) == n else f'found')
    x = int(input("What to search: "))
    start = time.time()
    linear_search(x, li)
    print(binary_search(x, li))
    end = time.time()
    print("The time of execution of above program is :", (end - start) * 10 ** 12, "ms")
    print(end-start)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
