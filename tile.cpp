#include "tile.h"
#include <iostream>

Tile::Tile( int num ) : m_num(num) {}

bool Tile::isEmpty() const { return m_num == 0; }

int Tile::getNum() const { return m_num; }

void Tile::display() const{
    if ( m_num == 0 ){
        std::cout << "    ";
    }
    else if ( m_num <= 9 ){
        std::cout << "  " << m_num << " ";
    }
    else{
        std::cout << " " << m_num << " ";
    }
}