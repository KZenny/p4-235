#include "Bishop.hpp"

/**
 * @brief Default Constructor.
 * @post Sets piece_size_ to 3 and type to "BISHOP"
 */
Bishop::Bishop() : ChessPiece() { setSize(3); setType("BISHOP"); }

/**
 * @brief Parameterized constructor.
 * @param color: The color of the Bishop.
 * @param row: 0-indexed row position of the Bishop.
 * @param col: 0-indexed column position of the Bishop.
 * @param movingUp: Flag indicating whether the Bishop is moving up.
 */
Bishop::Bishop(const std::string& color, const int& row, const int& col, const bool& movingUp)
    : ChessPiece(color, row, col, movingUp, 3, "BISHOP") {}

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
 bool Bishop::canMove(int target_row, int target_col, std::vector<std::vector<ChessPiece*>> board) const {
    // Check if the target position is within the board's bounds
    if (target_row < 0 || target_row >= BOARD_LENGTH || target_col < 0 || target_col >= BOARD_LENGTH) {
        return false;
    }

    // Check if the Bishop is trying to move to its current position
    if (target_row == row_ && target_col == column_) {
        return false;
    }

    // Check if the Bishop is moving diagonally
    if (std::abs(target_row - row_) != std::abs(target_col - column_)) {
        return false;
    }

    // Check for unobstructed path
    int row_step = (target_row > row_) ? 1 : -1;
    int col_step = (target_col > column_) ? 1 : -1;

    for (int r = row_ + row_step, c = column_ + col_step; r != target_row && c != target_col; r += row_step, c += col_step) {
        if (board[r][c] != nullptr) {
            return false; // Path is obstructed
        }
    }

    // Check if the target square is empty or contains a piece of another color
    ChessPiece* target_piece = board[target_row][target_col];
    if (target_piece != nullptr && target_piece->getColor() == color_) {
        return false; // Cannot capture own piece
    }

    return true; // Valid move  
}