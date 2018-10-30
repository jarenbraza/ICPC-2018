# Nick Graeff ACM Preseident, Problem: P112

# We need re to easily determine whether a character is a number
# We need sys to exit if an invalid token was found (though the input is assumed
# to be correct this is a good practice especially if we are testing our own
# cases and we mistype)
import re
import sys

# This function gets the number of open parentheses in the string and is used
# to drive the input reader so it knows when to stop reading the current case
def get_number_of_open_parentheses(some_string, left_paren_without_a_right_paren):
    # If the string is empty then we have presumably found all open parens
    # assuming the input was correct
    if some_string == None:
        return 0

    # For every character in the string, count the open parens based off of whether
    # they are a paren or not
    for character in some_string:
        if character == '(':
            left_paren_without_a_right_paren += 1
        elif character == ')':
            left_paren_without_a_right_paren -= 1
    return left_paren_without_a_right_paren

# This too is used to determine whether the currect case has ended by the input reader
def end_of_file_reached(some_string):
    return True if (some_string == None or some_string == "") else False

# This is a node class we use to create the binary tree
class node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.isLeaf = True

    # Add a node ot our tree and change the isLeaf value based on whether or not
    # newNode is None
    def add_node_to_tree(self, newNode, isLeftNode):
        if newNode:
            if isLeftNode:
                self.left = newNode
                self.isLeaf = False
            else:
                self.right = newNode
                self.isLeaf = False

# This is our custom lexer
# It accepts whitespace, LPAREN, RPAREN, and numeric values and return them after
# searching the string
# If a token not in the above language is given it will error
# Did not bother dealing with running into EOF for this problem, that could produce
# strange errors
class lexer():

    # Initialize our string with the input for this case
    def __init__(self, theinput):
        self.myinput = theinput
        self.myposition = 0

    # Return only the value that our parser wants, no whitespace, no strings in place
    # of numbers, etc.
    def find_next_token(self):

        # Ignore whitespace
        while self.myinput[self.myposition] == ' ':
            self.myposition += 1

        # If this is a left paren, increment the position and return the paren
        if self.myinput[self.myposition] == '(':
            self.myposition += 1
            return '('

        # If this is a right paren increment the position and return the paren
        if self.myinput[self.myposition] == ')':
            self.myposition += 1
            return ')'

        # Only other option is the token is a number, get its position in the string
        # and return it
        temp = self.myposition
        if re.search('[0-9]', self.myinput[self.myposition]):
            while re.search('[0-9]', self.myinput[self.myposition]):
                self.myposition += 1
            return int(self.myinput[temp:self.myposition])

        # else this was an invalid symbol, error
        print('Error, invalid token found: {0}'.format(self.myinput[self.myposition]))
        sys.exit()

# This method uses recursive descent to produce a binary tree by parsing the input
# provided by the lexer for the current case in the problem
# It errors when something unexpected appears, useful for debugging though unrequired
# the grammar it uses is below (VERY simple grammar)
# Context-Free Grammar
# A -> (num A A) | ()
def parse_A_and_return_root_of_binary_tree(mylexer):

    # The function creates a new root each time it is called and returns it
    # Initially the root is None
    root = None

    # This should always be '('
    # A -> (.num A A) | A -> (.)
    token = mylexer.find_next_token()
    if token != '(':
        print('Error, token found: {0}\nExpected: {1}'.format(token, '('))
        sys.exit()

    # If the token is a number insert it into the tree
    # if it is a right paren then return the null root
    # Otherwise error
    token = mylexer.find_next_token()

    # A -> (). | A -> (num . A A)
    if isinstance(token, int):
        root = node(token)

        # A -> (num A . A)
        root.add_node_to_tree(parse_A_and_return_root_of_binary_tree(mylexer), True)

        # A -> (num A A .)
        root.add_node_to_tree(parse_A_and_return_root_of_binary_tree(mylexer), False)
        token = mylexer.find_next_token()

        # A -> (num A A ) .
        # We are finished with this parse if this token is a ')'
        if token != ')':
            print('Error, token found: {0}\nExpected: {1}'.format(token, ')'))
            sys.exit()
    elif token != ')':
        print('Error, token found: {0}\nExpected: {1}'.format(token, ')'))
        sys.exit()

    return root

# Simply do a DFS on the tree, adding the sum the whole way to each leaf/node, and
# if any equal the sum, return true
def there_is_a_path_sum_in_the_binary_tree(root, sum):

    # Base case: root is non-existent, thus the sum was not found
    if root == None:
        return False

    # Base case, root is a leaf, if its value is the sum we found it, else we didn't
    if root.isLeaf:
        if root.value == sum:
            return True
        else:
            return False
    else:

        # Check the left and right branches to see if either produced the sum
        local_answer = False
        if root.left:
            root.left.value += root.value
            local_answer = local_answer or there_is_a_path_sum_in_the_binary_tree(root.left, sum)
        if root.right:
            root.right.value += root.value
            local_answer = local_answer or there_is_a_path_sum_in_the_binary_tree(root.right, sum)
        return local_answer

if __name__ == "__main__":

    # We need to loop through every line from the user until eof at least once
    # (do-while loop not available in Python)
    unparsed_input = input()
    while True:

        # Reset the test case we're on each time
        parsed_input = ''

        # If we reached the end of file, time to stop
        if end_of_file_reached(unparsed_input):
            break

        # Get the position of the first parentheses, everything before it is going
        # to be the sum this iteration needs to try finding, everything after is
        # the tree itself
        position_of_first_left_paren = unparsed_input.find('(')
        root_to_leaf_path_sum = int(unparsed_input[:position_of_first_left_paren])
        unparsed_input = unparsed_input[position_of_first_left_paren:]

        # Loop through however many lines you need to until the end of
        # input has occurred or the number of open parentheses is 0
        number_of_open_parens = get_number_of_open_parentheses(unparsed_input, 0)
        while (not end_of_file_reached(unparsed_input)) and number_of_open_parens > 0:
            parsed_input += unparsed_input
            unparsed_input = input()
            number_of_open_parens = get_number_of_open_parentheses(unparsed_input, number_of_open_parens)
        parsed_input += unparsed_input

        # Create the binary tree and return the root to it
        the_lexer = lexer(parsed_input)
        root_of_tree = parse_A_and_return_root_of_binary_tree(the_lexer)

        # Determine whether or not a path exists in the tree that sums to
        # root_to_leaf_path_sum
        if there_is_a_path_sum_in_the_binary_tree(root_of_tree, root_to_leaf_path_sum):
            print('yes')
        else:
            print('no')
            
        # Get the next binary tree
        unparsed_input = input()
