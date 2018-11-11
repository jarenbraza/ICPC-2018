import re
import sys

# returns a number
def char_to_num(charthing):
    if re.search("[0-9]", charthing):
        return int(charthing)
    else:
        return ord(charthing.upper())-55

def num_to_char(charthing):
    if charthing >= 10:
        return chr(charthing+55)
    else:
        return str(charthing)

# returns int base 10
def convert_to_base10(string, current_base):
    result = 0
    for index, char in enumerate(string[-1::-1]):
        result += char_to_num(char) * (current_base ** index)
    return result

# returns string
def convert_base10_to_somebase(number, somebase):
    arr = []
    while number:
        arr.append(num_to_char(number % somebase))
        number //= somebase
    return "".join(reversed(arr))

def convert_to_somebase(number, current_base, somebase):
    base10number = convert_to_base10(number, current_base)
    return convert_base10_to_somebase(base10number, somebase)

def min_base(string):
    min_base = 2
    for char in string:
        min_base = max(min_base, char_to_num(char)+1)
    return min_base

# get the input
for index, line in enumerate(sys.stdin):

    if index == 0:
        n_lines = int(line)
    else:
        string1, string2 = line.split()
        flag = False
        for i in range(min_base(string1), 37):
            for j in range(min_base(string2), 37):
                comp_string1 = convert_to_somebase(string1, i, j)
                if comp_string1 == string2:
                    print("yes")
                    flag = True
                    break
            if flag:
                break
        if not flag:
            print("no")
