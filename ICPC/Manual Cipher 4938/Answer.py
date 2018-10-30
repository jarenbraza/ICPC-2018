#Nick Graeff ACM VP Manual Cipher 4938

import math

shift_info = raw_input().split(':')
offset = [65-ord(x) for x in shift_info[0]]

# Get the length of the loop
# i.e. for BLUE:2314 we do 2+3+1+4 = 10
length_of_loop = 0
for i in shift_info[1]:
	length_of_loop += int(i)

# Start reading in the strings
thestring = raw_input()
while thestring:
	answer = ""
	string_length_multiplier = int(math.ceil(len(thestring)/length_of_loop))+1

	# Make an array of the offsets for each character
	ordering = []
	for index, i in enumerate(shift_info[1]):
		for j in range(int(i)):
			ordering.append(offset[index])

	# Make the array at least as long as the string and then 
	# slice it to be the same length
	ordering = (ordering*string_length_multiplier)[:len(thestring)] # 231423142314
	
	# Decrypt the string by adding the offset and converting it back
	# into ASCII, special case for space
	for i, j in zip(thestring, ordering):
		if (((ord(i)+j)-65)%27)+65 == 65+26:
			answer += ' '
		else:
			answer += chr((((ord(i)+j)-65)%27)+65)
	print answer.lower()
	thestring=raw_input()

# Sample input
# BLUE:2314
# XBDCZGDEVIAZZEKMLIVI
# NPCAEBXSIWAVYMPUVEFPFACPYXDRIXUJYR
# CBBVKKYRRMOHKWZPDWIREAXZBYDXVIFT