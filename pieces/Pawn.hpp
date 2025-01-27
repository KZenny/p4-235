#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include "ChessPiece.hpp"

class Pawn : public ChessPiece {
    public:
        /**
         * @brief Default Constructor. All boolean values are default initialized to false.
         * @note Remember to construct the base-class as well
         */
        Pawn();

        /**
        * @brief Parameterized constructor.
        * @param : A const reference to the color of the Pawn (a string). Set the color "BLACK" if the provided string contains non-alphabetic characters. 
        *     If the string is purely alphabetic, it is converted and stored in uppercase.
        *     NOTE: We do not supply a default value for color, the first parameter. Notice that if we do, we override the default constructor.
        * @param : The 0-indexed row position of the Pawn (as a const reference to an integer). Default value -1 if not provided, or if the value provided is outside the board's dimensions, [0, BOARD_LENGTH)
        * @param : The 0-indexed column position of the Pawn (as a const reference to an integer). Default value -1 if not provided, or if the value provided is outside the board's dimensions, [0, BOARD_LENGTH)
        * @param : A flag indicating whether the Pawn is moving up on the board, or not (as a const reference to a boolean). Default value false if not provided.
        * @post : The private members are set to the values of the corresponding parameters. 
        *   If either of row or col are out-of-bounds and set to -1, the other is also set to -1 (regardless of being in-bounds or not).
        */
        Pawn(const std::string& color, const int& row = -1, const int& col = -1, const bool& movingUp = false);

        /**
         * @brief Gets the value of the flag for the Pawn can double jump
         * @return The boolean value stored in double_jumpable_
         */
        bool canDoubleJump() const;


        /**
         * @brief Determines if this pawn can be promoted to another piece
         *     A pawn can be promoted if its row has reached the farthest row it can move up (or down) to. This is determined by the board size and the Piece's movingUp_ member.
         *
         *     EXAMPLE: If a pawn is movingUp and the board has 8 rows, then it can promoted only if it is in the 7th row (0-indexed)
         * @return True if this pawn can be promoted. False otherwise.
         */
        bool canPromote() const;

        /**
         * @brief Determines if this Pawn piece can move to the cell specified by (target_row, target_col) on the given board.
         * @pre The row & col members of the Pawn object match its actual position on the board.
         * @param target_row The row index to move to.
         * @param target_col The column index to move to.
         * @param board A 2D vector representing the current board state, where each cell points to a ChessPiece object or is null.
         * @return Returns true if the Pawn can legally move to the specified space; false otherwise.
         * 
         * The Pawn's movement follows these rules:
         * 1. The Pawn moves forward one square, but captures one square diagonally forward.
         * 2. The Pawn may move two squares forward on its first move, provided both squares are unoccupied.
         * 3. The move is invalid if the target square is outside the bounds of the board.
         * 
         */
        bool canMove(const int& target_row, const int& target_col, const std::vector<std::vector<ChessPiece*>>& board) const ;
};