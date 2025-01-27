#include "Knight.hpp"

/**
 * @brief Default Constructor.
 * @post Sets piece_size_ to 3 and type to "KNIGHT"
 */
Knight::Knight() : ChessPiece() { setSize(3); setType("KNIGHT"); }

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
Knight::Knight(const std::string& color, const int& row, const int& col, const bool& movingUp)
    : ChessPiece(color, row, col, movingUp, 3, "KNIGHT") {}

bool Knight::canMove(const int& target_row, const int& target_col, const std::vector<std::vector<ChessPiece*>>& board) const {
    // Not on the board
    if (getRow() == -1 || getColumn() == -1) { return false; }

    // Out of bounds target
    if (target_row < 0 || target_row >= BOARD_LENGTH || target_col < 0 || target_col >= BOARD_LENGTH) { return false; }

    ChessPiece* target_piece = board[target_row][target_col];
    if (target_piece && target_piece->getColor() == getColor()) { return false; }

    int abs_dx = std::abs(getRow() - target_row);
    int abs_dy = std::abs(getColumn() - target_col);

    // Check for an L-shape move pattern
    return (abs_dx == 1 && abs_dy == 2) || (abs_dx == 2 && abs_dy == 1);
}