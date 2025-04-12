#pragma once

#include <iostream>
#include "ChessPiece.hpp"

/**
 * @brief Bishop class inheriting from ChessPiece.
 */
class Bishop : public ChessPiece {
public:
    /**
     * @brief Default Constructor for Bishop. 
     * @post Sets piece_size_ to 3 and type to "BISHOP"
     */
    Bishop();

    /**
     * @brief Parameterized constructor.
     * @param color: The color of the Bishop.
     * @param row: 0-indexed row position of the Bishop.
     * @param col: 0-indexed column position of the Bishop.
     * @param movingUp: Flag indicating whether the Bishop is moving up on the board.
     */
    Bishop(const std::string& color, const int& row = -1, const int& col = -1, const bool& movingUp = false);

    // YOUR CODE HERE
    /**
    * @brief Determines whether the Bishop can move to the specified target position on the board.
    * @pre The row & col members of the Bishop object match its actual position on the passed board object.
    * 
    * The Bishop's movement follows these rules:
    * 1. The Bishop may move any number of squares diagonally from its current position
    * 2. The path to the target square must be unobstructed by (ie. contain) other pieces, 
    *      except for the target square itself.
    * 3. The target square must either be empty (moving) or contain a piece of another color (capturing)
    * 4. The target square must stay within the board's bounds, ie. not outside [0, BOARD_LENGTH)
    * 5. The Bishop cannot move to its currently occupied position (i.e. it can't stand still).
    * 
    * @param target_row An integer representing the row index of the target square on the board.
    * @param target_col An integer representing the column index of the target square on the board.
    * @param board A 2D vector representing the current board state, 
    *              where each cell points to a ChessPiece object or is null.
    * 
    * @return True if the Bishop can move to the specified position; false otherwise.
    */
    virtual bool canMove(int target_row, int target_col, std::vector<std::vector<ChessPiece*>> board) const override;

};