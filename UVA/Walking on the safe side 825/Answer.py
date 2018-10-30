# Nick Graeff ACM VP 
# Problem Description: 
# 	Number of ways to get to a destination in the minimum amount of steps

# This checks if the move being made is valid
# Valid means two things
# The first is that the move is in bounds 
# The second is that the spot has never been visited before or that 
# if it has been visited before the distance was the same as the last
# node which visited it (occurred on the same iteration of the bfs)
def is_valid_move(graph, start_row, start_col, row, col):
	if row >= 0 and row < len(graph) and col >= 0 and col < len(graph[0]) and \
	(graph[row][col] == graph[start_row][start_col]+1 or graph[row][col] == 0):
		return True
	else:
		return False
		
# Conduct a bfs on the graph marking the distance each node
# is from the start
# If the distance from two nodes to another is the same
# increment the number of ways to reach that node
# Once the goal is found, stop pushing things to the queue
# (prevents future iterations from running if there are many
# paths which do not lead to the goal and instead lead to oblivion)
def dynamic_bfs(graph, start_row, start_col, dest_row, dest_col):

	#Initialize the number of ways to get to each node as 0
	num_ways = [[0 for x in range(len(graph[0]))] for y in range(len(graph))]
	
	# The distance from the start node to itself and the number of 
	# ways to reach the start node is 1
	graph[start_row][start_col] = 1
	num_ways[start_row][start_col] = 1
	
	# We initialize the queue with the initial coordinate pair (0, 0)
	queue = [(start_row, start_col)]
	goal_not_found = True # Stops the bfs early if the goal is found
	pos = 0 # Keeps track of where we are in the 'queue' (using an array)
	
	# While the 'queue' is not empty
	while pos < len(queue):
	
		# 'pop' from the 'queue'
		start_row, start_col = queue[pos]
		pos += 1
		
		# Move in the up, right, down, left directions from the current position
		for move in [-1, 1]:
			
			# If the left/right move is valid
			if is_valid_move(graph, start_row, start_col, start_row+move, start_col):
				
				# Increment the distance and the number of ways to reach that node
				graph[start_row+move][start_col] = graph[start_row][start_col]+1
				num_ways[start_row+move][start_col] += 1
				
				# If we reached the goal, stop bfs early
				if start_row+move == dest_row and start_col == dest_col:
					goal_not_found = False
					
				# If we haven't reached the goal, keep pushing to the queue
				if goal_not_found:
					queue.append((start_row+move, start_col))
				
			# Same as above except for the up/down directions
			if is_valid_move(graph, start_row, start_col, start_row, start_col+move):
				graph[start_row][start_col+move] = graph[start_row][start_col]+1
				num_ways[start_row][start_col+move] += 1
				if start_row+move == dest_row and start_col == dest_col:
					goal_not_found = False
				if goal_not_found:
					queue.append((start_row, start_col+move))
					
	# The goal position now holds the number of ways to reach it
	# This number will be 0 if there is no way to reach the goal
	# (the problem did not ask us to account for this though)
	return num_ways[dest_row][dest_col]
	
# Get the number of graphs we need to solve this problem for
n = int(raw_input())
raw_input() # ignore empty line

# While we still have graphs to solve
while n:
	
	# Get the rows and columns and allocated a new graph
	rows, cols = [int(x) for x in raw_input().split()]
	graph = [[0 for x in range(cols)] for y in range(rows)]
	
	# Mark positions where there is an 'underground passage'
	# a.k.a. a barrier we cannot pass through
	for row in range(rows):
		line = raw_input().split()
		if len(line) > 1:
			for col in range(1, len(line)):
				graph[row][int(line[col])-1] = 1000000000 # essentially infinity
	
	# Find and print the answer
	print dynamic_bfs(graph, 0, 0, len(graph)-1, len(graph[0])-1)

	raw_input() #ignore the empty line
	
	# One less graph to solve
	n -= 1
		
# Sample Input
# 1
#
# 4 5
# 1
# 2 2
# 3 3 5
# 4
#


# Sample Output
# 4