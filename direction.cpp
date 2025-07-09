#include "direction.h"
#include "random.h"

Direction::Direction( Type direction ) : m_type( direction ) {}

Direction::Type Direction::getDirection() { return m_type; }

void Direction::changeDirection( Type direction ) { m_type = direction; }

Direction::Type Direction::getRandomDirection(){
    return static_cast<Type>( Random::get( 0, Type::TOTAL_DIRECTIONS - 1 ) );
}