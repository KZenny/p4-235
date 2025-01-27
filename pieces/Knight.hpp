#pragma once

#include <iostream>
#include <vector>
#include "ChessPiece.hpp"


/**
 * @brief Knight class inheriting from ChessPiece.
 */
class Knight : public ChessPiece {
public:
    /**
     * @brief Default Constructor for Knight. 
     * @post Sets piece_size_ to 3 and type to "KNIGHT"
     */
    Knight();

    /**
     * @brief Parameterized constructor.
     * @param color: The color of the Knight.
     * @param row: 0-indexed row position of the Knight.
     * @param col: 0-indexed column position of the Knight.
     * @param movingUp: Flag indicating whether the Knight is moving up on the board.
     */
    Knight(const std::string& color, const int& row = -1, const int& col = -1, const bool& movingUp = false);

    /**
     * @brief Determines if this Knight piece can move to the cell specified by (target_row, target_col) on the given board.
     * @pre The row & col members of the calling Knight object are set to its actual stored location on the board.
     * @param target_row The row index to move to.
     * @param target_col The column index to move to.
     * @param board A 2D vector representing the current board state, where each cell points to a ChessPiece object or is null.
     * @return Returns true if the Knight can legally move to the specified space on the board; false otherwise.
     * 
     * The Knight's movement follows these rules:
     * 1. The move must follow an "L" shape: two squares in one direction (vertical or horizontal) and one square perpendicular,
     *    or one square in one direction and two squares perpendicular.
     * 2. The Knight can jump over other pieces, so intervening pieces between its starting and target positions are ignored.
     * 3. The move is valid if the target square is empty or contains a piece of a different color (capturing).
     * 4. The move is invalid if the target square is outside the bounds of the board.
     * 
     * @note Capturing an opponent's piece by landing on its position is considered a valid move.
     */
    bool canMove(const int& target_row, const int& target_col, const std::vector<std::vector<ChessPiece*>>& board) const ;
};