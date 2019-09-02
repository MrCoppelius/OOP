#include "Triangle.h"
#define SIZE 3

Triangle::Triangle() : Triangle(0, 0, 0) {}

Triangle::Triangle(size_t a, size_t b, size_t c) : side_a(a), side_b(b), side_c(c) {
}

Triangle::Triangle(const Triangle& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

TAllocBlock Triangle::TriangleAllocator(sizeof(Triangle), SIZE);

double Triangle::Square() {
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));
}

void Triangle::Print() {
	std::cout << *this;
}

Triangle& Triangle::operator = (const Triangle& right) {
	if (this == &right) return *this;

	side_a = right.side_a;
	side_b = right.side_b;
	side_c = right.side_c;
	return *this;
}

Triangle& Triangle::operator ++ () {
	side_a++;
	side_c++;
	side_b++;
	return *this;
}

void* Triangle::operator new (size_t size) {
	return TriangleAllocator.allocate();
}

void Triangle::operator delete(void *p) {
	TriangleAllocator.deallocate(p);
}

Triangle::~Triangle() {
}

std::ostream& operator << (std::ostream& os, const Triangle& obj) {

	os << "a=" << obj.side_a << " " << "b=" << obj.side_b << " " << "c=" << obj.side_c << " ";
	return os;
}

std::istream& operator >> (std::istream& is, Triangle& obj) {
	is >> obj.side_a >> obj.side_b >> obj.side_c;
	return is;
}
bool operator==(const Triangle& left, const Triangle& right) {
	return ((left.side_a == right.side_a)&& (left.side_b == right.side_b)&&(left.side_c == right.side_c));
}