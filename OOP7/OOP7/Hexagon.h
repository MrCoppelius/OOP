#pragma once
#include "Figure.h"
#include "TAllocBlock.h"


class Hexagon: public Figure{
    public:
        Hexagon();
        Hexagon(size_t a);
        Hexagon(const Hexagon& orig);
        Hexagon& operator++();
        double Square();
		void Print();
        friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
        friend std::istream& operator>>(std::istream& is, Hexagon& obj);
        friend  bool operator ==(const Hexagon& left, const Hexagon& right);
        Hexagon& operator=(const Hexagon& right);
		void* operator new (size_t size);
		void operator delete(void *ptr);
        virtual ~Hexagon();
    private:
		static  TAllocBlock  HexagonAllocator;
        size_t side_a;

};

