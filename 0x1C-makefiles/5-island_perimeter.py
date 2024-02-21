#!/usr/bin/python3

"""This module attempts to solve the Island Perimeter coding challenge."""


def island_perimeter(grid: "list[list]") -> int:
    """Calculates the perimeter of an island.

    Args:
        grid (list[list]): a grid containing the binary matrix.

    Returns:
        int: The perimeter of the island.
    """
    try:
        # handle cases where the grid is empty
        rows, cols = len(grid), len(grid[0])
    except IndexError:
        return 0  # the perimeter is zero since the grid is empty

    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:  # if the cell is land, then...
                perimeter += 4  # start with 4 sides (it's a square)

                # subtract 2 for each adjacent land cell...
                # (to avoid double counting)
                if row > 0 and grid[row - 1][col] == 1:  # check the cell above
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] == 1:  # check the left cell
                    perimeter -= 2

    return perimeter
