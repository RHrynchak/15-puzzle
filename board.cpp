#include "board.h"
#include "constants.h"
#include <algorithm>

Board::Board( int shuffles ){
    for ( int i = 0; i < shuffles; ++i ){
        moveTiles( Direction::getRandomDirection() );
    }
}

void Board::display( SDL_Renderer* renderer ) const{
    
    for ( int y = 0; y < BOARD_SIZE; ++y ){
        for ( int x = 0; x < BOARD_SIZE; ++x ){
            m_board[ x ][ y ].display( renderer, x * TILE_WIDTH, y * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT); 
        }
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
    return {-1, -1};
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

bool Board::moveTiles( Direction direction ){
    Point p1 = findEmpty();
    Point p2 = p1.getAdjacentPoint( -direction );
    if ( Board::validPoint( p2 ) )
    {
        swapTiles( p1, p2 );
        return true;
    }
    return false;
}

bool Board::operator== ( const Board& other ) const{
    for ( int i = 0; i < BOARD_SIZE; ++i ){
        for ( int j = 0; j < BOARD_SIZE; ++j ){
            if ( m_board[i][j].getNum() != other.m_board[i][j].getNum() ){
                return false;
            }
        }
    }
    return true;
}

bool Board::isSolved() const{
    static Board solved(0);
    return solved == *this;
}