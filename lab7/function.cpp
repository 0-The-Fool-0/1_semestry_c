#include "Point4D.h"

// Конструкторы
Point4D::Point4D() : coords{0, 0, 0, 0} {}
Point4D::Point4D(double x, double y, double z, double w) : coords{x, y, z, w} {}
Point4D::Point4D(const Point4D& other) {
    for (int i = 0; i < 4; ++i) {
        coords[i] = other.coords[i];
    }
}

// Деструктор
Point4D::~Point4D() {}

// Методы доступа
double& Point4D::operator[](int index) {
    if (index < 0 || index >= 4) throw std::out_of_range("Index out of range!");
    return coords[index];
}

const double& Point4D::operator[](int index) const {
    if (index < 0 || index >= 4) throw std::out_of_range("Index out of range!");
    return coords[index];
}

// Унарные операторы
Point4D& Point4D::operator++() {
    for (int i = 0; i < 4; ++i) {
        coords[i]++;
    }
    return *this;
}

Point4D Point4D::operator++(int) {
    Point4D temp = *this;
    ++(*this);
    return temp;
}

Point4D& Point4D::operator--() {
    for (int i = 0; i < 4; ++i) {
        coords[i]--;
    }
    return *this;
}

Point4D Point4D::operator--(int) {
    Point4D temp = *this;
    --(*this);
    return temp;
}

Point4D Point4D::operator~() const {
    return Point4D(-coords[0], -coords[1], -coords[2], -coords[3]);
}

// Сравнение
bool Point4D::operator==(const Point4D& other) const {
    for (int i = 0; i < 4; ++i) {
        if (coords[i] != other.coords[i]) return false;
    }
    return true;
}

bool Point4D::operator!=(const Point4D& other) const {
    return !(*this == other);
}

// Дружественные функции
Point4D operator+(const Point4D& a, const Point4D& b) {
    return Point4D(a.coords[0] + b.coords[0], a.coords[1] + b.coords[1],
                   a.coords[2] + b.coords[2], a.coords[3] + b.coords[3]);
}

Point4D operator-(const Point4D& a, const Point4D& b) {
    return Point4D(a.coords[0] - b.coords[0], a.coords[1] - b.coords[1],
                   a.coords[2] - b.coords[2], a.coords[3] - b.coords[3]);
}

Point4D operator*(const Point4D& a, double scalar) {
    return Point4D(a.coords[0] * scalar, a.coords[1] * scalar,
                   a.coords[2] * scalar, a.coords[3] * scalar);
}

Point4D operator/(const Point4D& a, double scalar) {
    if (scalar == 0) throw std::invalid_argument("Division by zero!");
    return Point4D (a.coords[0] / scalar, a.coords[1] / scalar,
                   a.coords[2] / scalar, a.coords[3] / scalar);
}
Point4D operator/(const Point4D& a, const Point4D& b) {
    for (int i = 0; i < 4; ++i) {
        if (b.coords[i] == 0) throw std::invalid_argument("Division by zero!");
    }
    return Point4D(a.coords[0] / b.coords[0], a.coords[1] / b.coords[1],
                   a.coords[2] / b.coords[2], a.coords[3] / b.coords[3]);
}
Point4D operator*(const Point4D& a, const Point4D& b) {
    return Point4D(a.coords[0] / b.coords[0], a.coords[1] / b.coords[1],
                   a.coords[2] / b.coords[2], a.coords[3] / b.coords[3]);
}
std::ostream& operator<<(std::ostream& out, const Point4D& point) {
    out << "(" << point.coords[0] << ", " << point.coords[1] << ", "
        << point.coords[2] << ", " << point.coords[3] << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Point4D& point) {
    for (int i = 0; i < 4; ++i) {
        in >> point.coords[i];
    }
    return in;
}
