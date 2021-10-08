/** Lesson4a.cpp, by Kevin Wang
 * Create an enumerated type to keep track of the pieces on a chessboard
 * (ROOK, KNIGHT, etc. but EMPTY is also an option).
 * Then declare a 2-dimensional array
 * that represents the board itself (the type is the name of your enum). Fill the board.
 **/

#include <bits/stdc++.h>
using namespace std;

enum chessPiece {
    Pawn,
    Rook,
    Knight,
    Bishop,
    King,
    Queen,
    Empty
};

int main() {
    chessPiece board[8][8] = {
        {Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook},
        {Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn},
        {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
        {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
        {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
        {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
        {Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn},
        {Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook}
    };

    return 0;
}