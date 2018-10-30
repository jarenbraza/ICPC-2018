# Nick Graeff ACM VP Problem: Connect 7395

# Get the first line and determine the size of the square matrix
mystring = raw_input()
square_length = len(mystring)
num_points = 0
mypoints = []

# Push a coordinate pair (x, y) representing the position of each point
for i in range(square_length-1):
	for j in range(square_length):
		if mystring[j] == 'x':
			mypoints.append((i+1, j+1))
	mystring = raw_input()

print mypoints

# Determine which distances were unique between the elements
mydict = {}
for index, point in enumerate(mypoints):
	for compared_point in mypoints[index+1:]:
		distance = abs(point[0]-compared_point[0]) + abs(point[1]-compared_point[1])
		if distance in mydict:
			mydict[distance] = 1

# Print the unique distances
count = 0
for key, value in mydict.iteritems():
	count += 1
print count

# Note: this problem is asking you to print the length of the set of all distances.
# This means if you have distance: 30 and another distance: 30, this 
# should only count as 1 instead of 2 distances. Their use of the word
# 'unique' is a bit...unique.

# Sample Input

# 000000
# 00x000
# 000000
# 000x00
# 000x00
# 000000

# Sample Output
# 3

# Sample Input

# 00000000000000000000
# 000x00x0000000000000
# 000000000000000000x0
# 0x000000000000000x00
# 0000000000000000000x
# 00000000000000000x00
# 00000000000000000000
# 00000000000x00000000
# 00000000000000000000
# 0x00000000000000x000
# 0000x000000000000000
# 00x0000000000x000000
# 00x000000x000x0x0000
# 0x00000000x000x00000
# 00000000000x00000000
# 0000000000000000000x
# 00000000000000000000
# 00000000000000000000
# 0000x0000x0000000000
# 00000000000x00000000

# Sample Output
# 30