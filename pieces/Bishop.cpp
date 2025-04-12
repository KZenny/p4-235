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
bool Bishop::canMove(int target_row, int target_col, const std::vector<std::vector<ChessPiece*>>& board) const override{
    int current_row = getRow();
    int current_col = getColumn();

    // Check 1: Stay within bounds
    if (target_row < 0 || target_row >= BOARD_LENGTH || target_col < 0 || target_col >= BOARD_LENGTH)
        return false;

    // Check 2: Can't stand still
    if (target_row == current_row && target_col == current_col)
        return false;

    // Check 3: Must move diagonally
    if (std::abs(target_row - current_row) != std::abs(target_col - current_col))
        return false;

    // Determine direction of movement (delta row & col)
    int row_step = (target_row > current_row) ? 1 : -1;
    int col_step = (target_col > current_col) ? 1 : -1;

    int r = current_row + row_step;
    int c = current_col + col_step;

    // Check 4: All squares between current and target must be empty
    while (r != target_row && c != target_col) {
        if (board[r][c] != nullptr) {
            return false;
        }
        r += row_step;
        c += col_step;
    }

    // Check 5: Final square must be empty or occupied by enemy
    ChessPiece* target_piece = board[target_row][target_col];
    if (target_piece == nullptr) {
        return true; // empty square
    } else if (target_piece->getColor() != getColor()) {
        return true; // capture enemy piece
    }

    return false; // occupied by friendly piece
}