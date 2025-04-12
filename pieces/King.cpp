#include "King.hpp"

/**
 * @brief Default Constructor.
 * @post Sets piece_size_ to 4 and type to "KING"
 */
King::King() : ChessPiece() { setSize(4); setType("KING"); }

/**
 * @brief Parameterized constructor.
 * @param color: The color of the King.
 * @param row: 0-indexed row position of the King.
 * @param col: 0-indexed column position of the King.
 * @param movingUp: Flag indicating whether the King is moving up.
 */
King::King(const std::string& color, const int& row, const int& col, const bool& movingUp)
    : ChessPiece(color, row, col, movingUp, 4, "KING") {}

// YOUR CODE HERE 
/**
 * @brief Determines whether the King can move to the specified target position on the board.
 * @pre The row & col members of the Rook object match its actual position on the passed board object.
 * 
 * The King's movement follows these rules:
 * 1. The King can move only one square in any direction.
 * 2. The target square must either be empty (moving) or contain a piece of another color (capturing)
 * 3. The target square must stay within the board's bounds, ie. not outside [0, BOARD_LENGTH)
 * 4. The King cannot move to its currently occupied position (ie. it can't stand still).
 * 
 * @param target_row An integer reprsenting the row index of the target square on the board.
 * @param target_col An integer reprsenting the column index of the target square on the board.
 * @param board A 2D vector representing the current board state, 
 *              where each cell points to a ChessPiece object or is null.
 * 
 * @return True if the King can move to the specified position; false otherwise.
 */
bool King::canMove(const int& target_row, const int& target_col, const std::vector<std::vector<ChessPiece*>>& board) const {
    int current_row = getRow();
    int current_col = getColumn();

    // Rule 3: Check if target is within bounds
    if (target_row < 0 || target_row >= BOARD_LENGTH || target_col < 0 || target_col >= BOARD_LENGTH) {
        return false;
    }

    // Rule 4: Cannot move to the same position
    if (target_row == current_row && target_col == current_col) {
        return false;
    }

    // Rule 1: King can move one square in any direction
    int row_diff = std::abs(target_row - current_row);
    int col_diff = std::abs(target_col - current_col);
    if (row_diff > 1 || col_diff > 1) {
        return false;
    }

    // Rule 2: Target must be empty or occupied by an enemy piece
    ChessPiece* destination = board[target_row][target_col];
    if (destination == nullptr) {
        return true; // Empty square
    } else {
        return destination->getColor() != getColor(); // Capture only if enemy
    }
 }