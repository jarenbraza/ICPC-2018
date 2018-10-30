# Nick Graeff ACM VP Problem: Maze Thing

# Flood fill function, used for things like Minesweeper
def do_flood_fill(graph, startx, starty):

	# Set the current position we're in as 'found'
	graph[startx][starty] = '#'

	# I manually wrote these out but you could probably be 
	# more elegant with a for loop, I just didn't want to 
	# think about it
	
	# This is literally just a DFS where we mark everything we find
	if graph[startx][starty-1] == ' ':
		do_flood_fill(graph, startx, starty-1)
		
	if graph[startx][starty+1] == ' ':
		do_flood_fill(graph, startx, starty+1)
		
	if graph[startx-1][starty] == ' ':
		do_flood_fill(graph, startx-1, starty)
		
	if graph[startx+1][starty] == ' ':
		do_flood_fill(graph, startx+1, starty)


# This is an output variable that I only use because 
# if I don't the output will occur between the input lines
# You could also probably use sys.stdout or something and flush
# the output manually but I didn't want to import modules
output = ''

# Get how many graphs they are going to give us and store each of them in memory
n = int(raw_input())
while n:

	# The max size of each graph is 30 x 80, just build the whole thing, 
	# doesn't take much space
	graph = [[' ' for x in range(80)] for y in range(30)]
	
	# Position at which there is a star, where we begin flood fill
	startx = 0
	starty = 0
	
	i = 0 # i keeps track of which line we're on
	line = raw_input()
	max_col_length = 0
	while line != '_____': # 5 underscores says this maze is over with
	
		for j, char in enumerate(line):
			if char != '*':
				graph[i][j] = char
			else:
				startx = i
				starty = j
		max_col_length = max(max_col_length, len(line))
		
		i += 1 # increment i here to represent the next line
		line = raw_input()
		
	# Now that we have the maze in memory, perform flood fill on it and print it
	do_flood_fill(graph, startx, starty)
	for line in graph[:i]: # Slicing in Python is bad mmk, loop by indice if you're not lazy
	
		# join() takes an array and puts '' between every element and turns it into a string
		output += "".join(line[:max_col_length]) + '\n'
	output += '_____\n'
	
	n -= 1 # Decrement the number of mazes we've handled so far and repeat the process

# Now that everything has been calculated print the output we were
# saving all this time	
print output

# Sample Input
# 2
# XXXXXXXXX
# X   X   X
# X *     X
# X   X   X
# XXXXXXXXX
# X   X
# X   X
# X   X
# XXXXX
# _____
# XXXXX
# X   X
# X * X
# X   X
# XXXXX
# _____

# Sample Output

# XXXXXXXXX
# X###X###X
# X#######X
# X###X###X
# XXXXXXXXX
# X   X
# X   X
# X   X
# XXXXX
# _____
# XXXXX
# X###X
# X###X
# X###X
# XXXXX