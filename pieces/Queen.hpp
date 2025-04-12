#pragma once

#include <iostream>
#include <vector>
#include "ChessPiece.hpp"


/**
 * @brief Queen class inheriting from ChessPiece.
 */
class Queen : public ChessPiece {
public:
    /**
     * @brief Default Constructor for Queen. 
     * @post Sets piece_size_ to 4 and type to "QUEEN"
     */
    Queen();

    /**
     * @brief Parameterized constructor.
     * @param color: The color of the Queen.
     * @param row: 0-indexed row position of the Queen.
     * @param col: 0-indexed column position of the Queen.
     * @param movingUp: Flag indicating whether the Queen is moving up on the board.
     */
    Queen(const std::string& color, const int& row = -1, const int& col = -1, const bool& movingUp = false);

    // YOUR CODE HERE 
    /**
    * @brief Determines whether the Queen can move to the specified target position on the board.
    * @pre The row & col members of the Queen object match its actual position on the passed board object.
    * 
    * The Queen's movement follows these rules:
    * 1. The Queen may move any number of squares
    *      vertically, horizontally, or diagonally from its current position
    * 2. The path to the target square must be unobstructed by (ie. contain) other pieces, 
    *      except for the target square itself.
    * 3. The target square must either be empty (moving) or contain a piece of another color (capturing)
    * 4. The target square must stay within the board's bounds, ie. not outside [0, BOARD_LENGTH)
    * 5. The Queen cannot move to its currently occupied position (i.e. it can't stand still).
    * 
    * @param target_row An integer representing the row index of the target square on the board.
    * @param target_col An integer representing the column index of the target square on the board.
    * @param board A 2D vector representing the current board state, 
    *              where each cell points to a ChessPiece object or is null.
    * 
    * @return True if the Queen can move to the specified position; false otherwise.
    */
    bool canMove(const int& target_row, const int& target_col, const std::vector<std::vector<ChessPiece*>>& board) const;
};