#include <iostream>
#include <string>
#include <locale> 

// Базовый класс для всех фигур
class Figure {
public:
    virtual void print_info() const = 0; // Чисто виртуальная функция для вывода информации
    virtual ~Figure() = default;
};

// Класс для треугольников
class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        std::cout << "Треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c
            << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
    }
};

// Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {}

    void print_info() const override {
        std::cout << "Прямоугольный треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c
            << "\nУглы: A=" << A << " B=" << B << " C=90\n" << std::endl;
    }
};

// Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {}

    void print_info() const override {
        std::cout << "Равнобедренный треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << a
            << "\nУглы: A=" << A << " B=" << B << " C=" << A << "\n" << std::endl;
    }
};

// Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side) : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override {
        std::cout << "Равносторонний треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c
            << "\nУглы: A=60 B=60 C=60\n" << std::endl;
    }
};

// Класс для четырёхугольников
class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override {
        std::cout << "Четырёхугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
            << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
    }
};

// Прямоугольник
class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {}

    void print_info() const override {
        std::cout << "Прямоугольник:\nСтороны: a=" << a << " b=" << b << " c=" << a << " d=" << b
            << "\nУглы: A=90 B=90 C=90 D=90\n" << std::endl;
    }
};

// Квадрат
class Square : public Rectangle {
public:
    Square(int side) : Rectangle(side, side) {}

    void print_info() const override {
        std::cout << "Квадрат:\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
            << "\nУглы: A=90 B=90 C=90 D=90\n" << std::endl;
    }
};

// Параллелограмм
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {}

    void print_info() const override {
        std::cout << "Параллелограмм:\nСтороны: a=" << a << " b=" << b << " c=" << a << " d=" << b
            << "\nУглы: A=" << A << " B=" << B << " C=" << A << " D=" << B << "\n" << std::endl;
    }
};

// Ромб
class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B) : Parallelogram(side, side, A, B) {}

    void print_info() const override {
        std::cout << "Ромб:\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
            << "\nУглы: A=" << A << " B=" << B << " C=" << A << " D=" << B << "\n" << std::endl;
    }
};

// Функция для вывода информации о фигуре
void print_info(const Figure* figure) {
    figure->print_info();
}

int main() {
    setlocale(LC_ALL, "Russian");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}
