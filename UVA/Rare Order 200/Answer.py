# Nick Graeff ACM VP Problem: Rare Order 200

# Convert a capitalized character to its alphabetical index (0 to 25)
def char_to_index(char):
	return ord(char)-65
	
# Convert an alphabetical index to its capital ASCII representation
def index_to_char(index):
	return chr(index+65)
	
# Simple class for a graph to add edges
# Built specifically for the alphabet (26 possible nodes) 
class alphabet_graph:

	# Initialize the class by setting every node to unvisited
	def __init__(self):
		self.nodes = [[] for x in range(26)]
		self.visited = [False]*26
		self.stack = []
	
	# Add an edge from node u to node v
	def add_edge_from_u_to_v(self, u, v):
		if not (char_to_index(v) in self.nodes[char_to_index(u)]):
			self.nodes[char_to_index(u)].append(char_to_index(v))
	
	# Do a DFS on the graph and push each vertex found to a stack after
	# all its nodes have been searched
	def topo_sort(self, source_vertex):
	
		self.visited[source_vertex] = True
		
		for this_node in self.nodes[source_vertex]:
			if self.visited[this_node]:
				continue
			self.topo_sort(this_node)
		
		self.stack.append(index_to_char(source_vertex))
			
	# Print the stack
	def print_vertices_sorted(self):
		print "".join(reversed(self.stack))
		
# Get the input
string_arr = []
a_string = raw_input()
while a_string != "#":
	string_arr.append(a_string)
	a_string = raw_input()

# Initialize the graph
the_graph = alphabet_graph()
	
# Compare each word to the next and create an edge which marks the first
# letter which is greater than another in the graph
for word_index in range(len(string_arr)-1):
	for letter_index in range(min(len(string_arr[word_index]), len(string_arr[word_index+1]))):
		if string_arr[word_index][letter_index] == string_arr[word_index+1][letter_index]:
			continue
		the_graph.add_edge_from_u_to_v(string_arr[word_index][letter_index], string_arr[word_index+1][letter_index])
		break;
# Do a topological sort and print it
the_graph.topo_sort(char_to_index(string_arr[0][0]))
the_graph.print_vertices_sorted()

# Sample Input
# XWY
# ZX
# ZXY
# ZXW
# YWWX
# #

# Sample Output
# XZYW