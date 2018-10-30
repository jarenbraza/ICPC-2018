# Nick Graeff ACM VP Problem: p10000?

# Simple class for a graph to add edges
class longest_path_graph:

	# Initialize the class by setting every node to unvisited
	def __init__(self, num_nodes):
		self.nodes = [[] for x in range(num_nodes)]
		self.visited = [False]*num_nodes
		self.max_lengths = [0]*num_nodes
		self.finishes_at = [0]*num_nodes
	
	# Add an edge from node u to node v
	def add_edge_from_u_to_v(self, u, v):
		self.nodes[u].append(v)
	
	# Do a DFS on the graph and set each node's maximum path to the max
	# of every path of every node it is connected to plus one
	def dfs_dynamic_programming(self, source_vertex, current_length):
	
		# Once we visit this node we don't want to visit again
		# Also if it has no nodes to connect to, it is its own finish
		self.visited[source_vertex] = True
		self.finishes_at[source_vertex] = source_vertex
		
		for this_node in self.nodes[source_vertex]:
		
			# If we haven't visited the node yet, visit it
			if not self.visited[this_node]:
				self.dfs_dynamic_programming(this_node, current_length+1)
			
			# The current node's maximum length is the maximum length of one of
			# its adjacent nodes plus one and its finish is the same as the finish
			# of that node
			if self.max_lengths[source_vertex] < self.max_lengths[this_node] + 1:
				self.max_lengths[source_vertex] = self.max_lengths[this_node] + 1
				self.finishes_at[source_vertex] = self.finishes_at[this_node]
		
	
# Get the number of nodes and start a counter for the output
number_of_nodes = int(raw_input())
counter = 1
while number_of_nodes != 0:
	# Get the start_node and make a graph
	start_node = int(raw_input())-1
	the_graph = longest_path_graph(number_of_nodes)
	
	# Add the edges
	u, v = [int(x) for x in raw_input().split()]
	while u and v:
		the_graph.add_edge_from_u_to_v(u-1, v-1)
		u, v = [int(x) for x in raw_input().split()]
		
	# Do a DFS and store the max length for the start node in the_graph.max_lengths[start_node]
	the_graph.dfs_dynamic_programming(start_node, 0)
	
	# Output, add one to some of the output because our arrays are zero-indexed
	print "Case {0}: The longest path from {1} has length {2}, finishing at {3}.".format(counter, start_node+1, the_graph.max_lengths[start_node], the_graph.finishes_at[start_node]+1)
	
	# Rinse and repeat
	counter += 1
	number_of_nodes = int(raw_input())

# Sample Input
# 2
# 1
# 1 2
# 0 0
# 5
# 3
# 1 2
# 3 5
# 3 1
# 2 4
# 4 5
# 0 0
# 5
# 5
# 5 1
# 5 2
# 5 3
# 5 4
# 4 1
# 4 2
# 0 0
# 0

# Sample Output 
# Case 1: The longest path from 1 has length 1, finishing at 2.
# Case 2: The longest path from 3 has length 4, finishing at 5.
# Case 3: The longest path from 5 has length 2, finishing at 1.