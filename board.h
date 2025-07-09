#pragma once
#include "tile.h"
#include "point.h"

class Board{
public:
    Board();
    static constexpr int BOARD_SIZE {4};
    void display() const;
    void moveTiles( Direction direction );
private:
    Point findEmpty() const;
    static bool validPoint( Point p );
    void swapTiles( Point p1, Point p2 );
    Tile m_board [ BOARD_SIZE ][ BOARD_SIZE ] {
        Tile{1}, Tile{5}, Tile{9}, Tile{13},
        Tile{2}, Tile{6}, Tile{10}, Tile{14},
        Tile{3}, Tile{7}, Tile{11}, Tile{15},
        Tile{4}, Tile{8}, Tile{12}, Tile{0},
    };
};