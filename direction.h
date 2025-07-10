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
    Type getType() const;
    void changeType( Type type );
    Direction operator- () const;
    static Direction getRandomDirection();
private:
    Type m_type;
};