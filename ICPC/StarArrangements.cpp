/*
    Here are my thoughts during the problem.

    Let the 'size' of a row be the number of stars in that row.

    Some constraints we know right off the bat from the problem description:
    (1) (Case 1-by-S) There must be more than one row.
    (2) (Case S-by-1) The size of the 1st row must be more than one.
    (3) Adjacent rows can differ in size by 0 or 1 ONLY.
    (4) The size of the 1st row cannot be less than that of the 2nd row.
    (5) Every other row has the same size.
    

    From (3), (4), and (5), we know that there are only two size pairs to consider:
    1. 1st row size == 2nd row size + 1    [Adjacent row sizes differ by 1]
    2. 1st row size == 2nd row size        [Adjacent row sizes differ by 0]

    An illustration of the above is as follows:

            Case 1             Case 2
    1st Row: * * *     1st Row:  * *
    2nd Row:  * *      2nd Row:  * *
    1st Row: * * *     1st Row:  * *
    2nd Row:  * *      2nd Row:  * *


    Additionally, we might have an extra 1st row, since we start with it in our arrangement.
    Thus, for each of those two size pairs, we need to consider the two possible row counts:
    1. 1st row count == 2nd row count + 1  [There is an extra 1st row at the end]
    2. 1st row count == 2nd row count      [Equal row counts]

    An illustration of the above is as follows:

            Case 1              Case 2
    1st Row: * * *     1st Row:  * * *
    2nd Row:  * *      2nd Row:   * *
    1st Row: * * *


    Finally, based on (1) and (2), we can figure out how to iterate through arrangements.
    - Set the first row size at 2.
    - Test for the second row size being equal or smaller by one than the first row size.
    - If either works, print out the sizes.
    - Iterate the first row size, and repeat.
*/

#include <iostream>

void solve(int numStars);
bool hasEqualRowSizes(int numStars, int firstRowSize, int secondRowSize);
bool hasExtraFirstRow(int numStars, int firstRowSize, int secondRowSize);

int main()
{
    int numStars;

    // Continually read in the number of stars to arrange
    while (std::cin >> numStars)
    {
        std::cout << numStars << ":" << std::endl;
        solve(numStars);
    }

    return 0;
}

// Prints possible "visually appealing" arrangements for the number of stars
void solve(int numStars)
{
    // Iterate through possible first row sizes
    for (int i = 2; i <= numStars / 2 + 1; i++)
    {
        // Case 1: Row sizes differ by one
        if (hasEqualRowSizes(numStars, i, i - 1) || hasExtraFirstRow(numStars, i, i - 1))
            std::cout << " " << i << "," << i - 1 << std::endl;
        
        // Case 2: Rows sizes are equal
        if (hasEqualRowSizes(numStars, i, i) || hasExtraFirstRow(numStars, i, i))
            std::cout << " " << i << "," << i << std::endl;
    }
}

// Returns if the combined row size is a factor of the number of stars
bool hasEqualRowSizes(int numStars, int firstRowSize, int secondRowSize)
{
    return (numStars % (firstRowSize + secondRowSize)) == 0;
}

// Returns if the combined row size is a factor of the number of stars (with extra first row)
bool hasExtraFirstRow(int numStars, int firstRowSize, int secondRowSize)
{
    return ((numStars - firstRowSize) % (firstRowSize + secondRowSize)) == 0;
}
