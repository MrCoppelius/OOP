#pragma once
#include <cstdlib>
#include <iostream>

class Hexagon{
    public:
        Hexagon();
        Hexagon(size_t a);
        Hexagon(const Hexagon& orig);
        Hexagon& operator++();
        double Square();
        friend Hexagon operator+ (const Hexagon& left, const Hexagon& right);
        friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
        friend std::istream& operator>>(std::istream& is, Hexagon& obj);
        friend  bool operator ==(const Hexagon& left, const Hexagon& right);
        Hexagon& operator=(const Hexagon& right);
        virtual ~Hexagon();
    private:
        size_t side_a;

};

