#include <iostream>

class Figure
{
public:

    Figure()
    {
        side_count = 0;
        name = "Фигура";
    }

    int getSideCount()
    {
        return side_count;
    }

    std::string getName()
    {
        return name;
    }

    ~Figure() {}

protected:
    int side_count;
    std::string name;
};

class Triangle : public Figure
{
public:
    Triangle() 
    {
        side_count = 3;
        name = "Треугольник";
    }
    ~Triangle() {}
};

class Rectangle : public Figure
{
public:
    Rectangle()
    {
        side_count = 4;
        name = "Четырёхугольник";
    }
    ~Rectangle() {}
};

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Количество сторон: ";
    Figure figure;
    std::cout << "\n" << figure.getName() << ": " << figure.getSideCount();
    Triangle triangle;
    std::cout << "\n" << triangle.getName() << ": " << triangle.getSideCount();
    Rectangle rectangle;
    std::cout << "\n" << rectangle.getName() << ": " << rectangle.getSideCount();

    return 0;
}