#pragma once

class Direction{
public:
    enum Type{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        TOTAL_DIRECTIONS
    };
    Direction() = default;
    Direction( Type type );
    Type getType();
    void changeType( Type type );
    
    static Direction getRandomDirection();
private:
    Type m_type;
};