#ifndef POINT4D_H
#define POINT4D_H

#include <iostream>
#include <stdexcept>

class Point4D {
private:
    double coords[4]; // Координаты точки

public:
    // Конструкторы
    Point4D();
    Point4D(double x, double y, double z, double w);
    Point4D(const Point4D& other);

    // Деструктор
    ~Point4D();

    // Методы доступа
    double& operator[](int index);
    const double& operator[](int index) const;

    // Унарные операторы
    Point4D& operator++();     // Префиксный
    Point4D operator++(int);  // Постфиксный
    Point4D& operator--();     // Префиксный
    Point4D operator--(int);  // Постфиксный
    Point4D operator~() const; // Отражение

    // Сравнение
    bool operator==(const Point4D& other) const;
    bool operator!=(const Point4D& other) const;

    // Дружественные функции для бинарных операторов
    friend Point4D operator+(const Point4D& a, const Point4D& b);
    friend Point4D operator-(const Point4D& a, const Point4D& b);
    friend Point4D operator/(const Point4D& a, const Point4D& b);
    friend Point4D operator*(const Point4D& a, const Point4D& b);
    friend Point4D operator*(const Point4D& a, double scalar);
    friend Point4D operator/(const Point4D& a, double scalar);
    friend std::ostream& operator<<(std::ostream& out, const Point4D& point);
    friend std::istream& operator>>(std::istream& in, Point4D& point);
};

#endif // POINT4D_H
