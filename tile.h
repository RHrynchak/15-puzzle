#pragma once

class Tile{
public:
    Tile() = default;
    explicit Tile( int num );
    bool isEmpty() const;
    int getNum() const;
    void display() const;
private:
    int m_num;
};