#pragma once
#include "tile.h"

class Board{
public:
    Board() = default;
    static constexpr int BOARD_SIZE {4};
    void display() const;
private:
    Tile m_board [ BOARD_SIZE ][ BOARD_SIZE ] {
        Tile{1}, Tile{2}, Tile{3}, Tile{4},
        Tile{5}, Tile{6}, Tile{7}, Tile{8},
        Tile{9}, Tile{10}, Tile{11}, Tile{12},
        Tile{13}, Tile{14}, Tile{15}, Tile{0},
    };
};