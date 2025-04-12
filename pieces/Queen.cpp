#include "Queen.hpp"

/**
 * @brief Default Constructor.
 * @post Sets piece_size_ to 9 and type to "QUEEN"
 */
Queen::Queen() : ChessPiece() { setSize(4); setType("QUEEN"); }

/**
 * @brief Parameterized constructor.
 * @param color: The color of the Queen.
 * @param row: 0-indexed row position of the Queen.
 * @param col: 0-indexed column position of the Queen.
 * @param movingUp: Flag indicating whether the Queen is moving up.
 */
Queen::Queen(const std::string& color, const int& row, const int& col, const bool& movingUp)
    : ChessPiece(color, row, col, movingUp, 4, "QUEEN") {}

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
bool Queen::canMove(int target_row, int target_col, const std::vector<std::vector<ChessPiece*>>& board) const override{
    int curr_row = getRow();
    int curr_col = getColumn();

    // 1. Stay within bounds
    if (target_row < 0 || target_row >= BOARD_LENGTH || target_col < 0 || target_col >= BOARD_LENGTH)
        return false;

    // 2. Can't move to current position
    if (target_row == curr_row && target_col == curr_col)
        return false;

    // Determine direction of movement
    int row_diff = target_row - curr_row;
    int col_diff = target_col - curr_col;

    int row_step = (row_diff == 0) ? 0 : (row_diff > 0 ? 1 : -1);
    int col_step = (col_diff == 0) ? 0 : (col_diff > 0 ? 1 : -1);

    // 3. Check if movement is straight or diagonal
    if (!(row_step == 0 || col_step == 0 || std::abs(row_diff) == std::abs(col_diff))) {
        return false;
    }

    // 4. Check if path is clear (excluding target square)
    int r = curr_row + row_step;
    int c = curr_col + col_step;
    while (r != target_row || c != target_col) {
        if (board[r][c] != nullptr)
            return false;
        r += row_step;
        c += col_step;
    }

    // 5. Check destination square: must be empty or opponent's piece
    ChessPiece* destination = board[target_row][target_col];
    if (destination == nullptr) {
        return true;
    } else {
        return destination->getColor() != getColor();
    }
}