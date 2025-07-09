#include "board.h"
#include <iostream>
#include "constants.h"

void Board::display() const{
    for ( int i = 0; i < g_ConsoleLines; ++i ){
        std::cout << std::endl;
    }
    
    for ( int y = 0; y < BOARD_SIZE; ++y ){
        for ( int x = 0; x < BOARD_SIZE; ++x ){
            m_board[ x ][ y ].display(); 
        }
        std::cout << std::endl;
    }
}

Point Board::findEmpty() const{
    for ( int i = 0; i < BOARD_SIZE; ++i ){
        for ( int j = 0; j < BOARD_SIZE; ++j){
            if ( m_board[ i ][ j ].isEmpty() ){
                return { i, j };
            }
        }
    }
}

bool Board::validPoint( Point p ){
    if ( p.m_x < 0 || p.m_y < 0 )
        return false;
    if ( p.m_x >= BOARD_SIZE || p.m_y >= BOARD_SIZE )
        return false;
    return true;
}

void Board::swapTiles( Point p1, Point p2 ){
    std::swap( m_board[ p1.m_x ][ p1.m_y ], m_board[ p2.m_x ][ p2.m_y ] );
}

void Board::moveTiles( Direction direction ){
    Point p1 = findEmpty();
    Point p2 = p1.getAdjacentPoint( -direction );
    if ( Board::validPoint( p2 ) )
        swapTiles( p1, p2 );
}