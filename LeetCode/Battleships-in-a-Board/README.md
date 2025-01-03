# Battleships in a Board

Can you solve this real interview question? Battleships in a Board - Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

 

Example 1:

[https://assets.leetcode.com/uploads/2024/06/21/image.png]


Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2


Example 2:


Input: board = [["."]]
Output: 0