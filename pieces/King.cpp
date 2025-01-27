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