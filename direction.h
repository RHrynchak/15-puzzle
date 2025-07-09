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
    Direction( Type direction );
    Type getDirection();
    void changeDirection( Type direction );
    static Type getRandomDirection();
private:
    Type m_type;
};