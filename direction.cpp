#include "direction.h"
#include "random.h"

Direction::Direction( Type type ) : m_type( type ) {}

Direction::Type Direction::getType() { return m_type; }

void Direction::changeType( Type type ) { m_type = type; }

Direction Direction::getRandomDirection(){
    return Direction { static_cast<Type>( Random::get( 0, Type::TOTAL_DIRECTIONS - 1 ) ) };
}