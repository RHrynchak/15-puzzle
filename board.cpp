#include "board.h"
#include <iostream>
#include "constants.h"

void Board::display() const{
    for ( int i = 0; i < g_ConsoleLines; ++i ){
        std::cout << std::endl;
    }
    
    for ( int i = 0; i < BOARD_SIZE; ++i ){
        for ( int j = 0; j < BOARD_SIZE; ++j ){
            m_board[ i ][ j ].display(); 
        }
        std::cout << std::endl;
    }
}