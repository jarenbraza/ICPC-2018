# Nick Graeff ACM VP Problem Disaster: Recovery Plans 4711

# This is just going to hold some basic information for each node
# ...Makes life easier
class some_node:
	def __init__(self, node_num):
		self.visited = None
		self.connections = []

# This just does a basic DFS on the graph
def do_dfs(the_graph, index, finish_queue):

	# do_dfs on each_connection in the_graph
	the_graph[index].visited = True
	for each_connection in the_graph[index].connections:
		if not the_graph[each_connection].visited:
			do_dfs(the_graph, each_connection, finish_queue)

	# Add the index of each node to the finish_queue in the 
	# order that they finished 
	finish_queue.append(index)

# Transpose the graph, this would be really easy if we used
# a matrix instead of an adjacency list
def do_transpose(the_graph):
	
	# Make a new_graph with all the nodes reset to unvisited
	# but switch the connections (i.e. instead of x->y do y->x)
	new_graph = [some_node(x) for x in range(len(the_graph))]
	for each_node in range(len(the_graph)):
		for each_connection in the_graph[each_node].connections:
			new_graph[each_connection].connections.append(each_node)
	return new_graph

# SCC Helper, slightly different from regular DFS because
# we want to add nodes which are strongly connected to their
# own array
def mod_dfs(the_graph, index, scc_array, scc_index):
	
	the_graph[index].visited = True
	scc_array[scc_index].append(index)

	for each_connection in the_graph[index].connections:
		if not the_graph[each_connection].visited:
			mod_dfs(the_graph, each_connection, scc_array, scc_index)
		
# Find the strongly connected components by doing a DFS in
# reverse order of the finishing times of the first DFS
#
# This works by finding the 'sink' vertices and seeing if 
# they're connected to anything
def find_scc(the_graph, finish_queue, scc_arr):

	# Start the SCC array of arrays at 0
	scc_index = 0
	for last_to_finish in reversed(range(len(finish_queue))):
		if not the_graph[finish_queue[last_to_finish]].visited:
			
			# Make a new array for this component and add all its buds
			# in mod_dfs to it as well 
			scc_arr.append([])
			mod_dfs(the_graph, finish_queue[last_to_finish], scc_arr, scc_index)
			scc_index += 1

# Get the name of the 'DRP'
name_of_drp = input()

# If the input wasn't blank keep doing this stuff
while name_of_drp:

	# Get the tasks_per_page and num_tasks 
	buff = input().split()
	tasks_per_page = int(buff[0])
	num_tasks = int(buff[1])

	# Create the graph (adjacency-list style)
	the_graph = [some_node(x) for x in range(num_tasks)]
	coord_pair = input()
	while coord_pair:
		coord_pair = coord_pair.split(',')
		the_graph[int(coord_pair[0])-1].connections.append(int(coord_pair[1])-1)
		coord_pair = input()
		
	#Solve the problem
	finish_queue = []
	scc_arr = []
	do_dfs(the_graph, 0, finish_queue)
	the_graph = do_transpose(the_graph)
	find_scc(the_graph, finish_queue, scc_arr)

	# Print the answer
	print(name_of_drp + ': ', end='')
	
	# If the length of any strongly connected components is
	# greater than the tasks_per_page then it isn't printable,
	# otherwise print the number of strongly connected components
	max_exceeded = False
	for sub_arr in scc_arr:
		if len(sub_arr) > tasks_per_page:
			max_exceeded = True
			break
	if max_exceeded:
		print("not printable")
	else:
		print(len(scc_arr))

	# Repeat the process
	name_of_drp = input()


# Sample Input
# Jolt Cola Shortage
# 4 8
# 1,2
# 2,5
# 5,1
# 2,6
# 5,6
# 2,3
# 6,7
# 7,6
# 3,4
# 4,3
# 5,7
# 4,8
# 8,4
# 8,7
# 
# Pizza Strike
# 2 4
# 1,2
# 2,3
# 3,1

# Sample Output
# Jolt Cola Shortage: 3
# Pizza Strike: not printable