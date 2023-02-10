#include <iostream>
#include <cmath>

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

	void virtual print() {}
protected:
	int side_count;
	std::string name;
};

class Triangle : public Figure
{
public:
	Triangle(double _a, double _b, double _c, double _A, double _B, double _C)
	{
		a = _a;
		b = _b;
		c = _c;
		A = _A;
		B = _B;
		C = _C;
		side_count = 3;
		name = "Треугольник";
	}

	~Triangle() {}

	double get_a()
	{
		return a;
	}

	double get_b()
	{
		return b;
	}

	double get_c()
	{
		return c;
	}

	double get_A()
	{
		return A;
	}

	double get_B()
	{
		return B;
	}

	double get_C()
	{
		return C;
	}

	void print() override
	{
		std::cout << "\n" << getName() << ":";
		std::cout << "\n" << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c();
		std::cout << "\n" << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C();
	}

protected:
	double a, b, c, A, B, C;
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D)
	{
		a = _a;
		b = _b;
		c = _c;
		d = _d;
		A = _A;
		B = _B;
		C = _C;
		D = _D;
		side_count = 4;
		name = "Четырёхугольник";
	}

	~Quadrilateral() {}

	double get_a()
	{
		return a;
	}

	double get_b()
	{
		return b;
	}

	double get_c()
	{
		return c;
	}

	double get_d()
	{
		return d;
	}

	double get_A()
	{
		return A;
	}

	double get_B()
	{
		return B;
	}

	double get_C()
	{
		return C;
	}

	double get_D()
	{
		return D;
	}

	void print() override
	{
		std::cout << "\n" << getName() << ":";
		std::cout << "\n" << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d();
		std::cout << "\n" << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D();

	}
protected:
	double a, b, c, d, A, B, C, D;
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
	{
		name = "Прямоугольный треугольник";
	}
	~RightTriangle() {}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(double a, double B) : Triangle(a, b, a, A, B, C)
	{
		A = (180 - B) / 2;
		C = A;
		b = sqrt(a * a + c * c - 2 * a * c * cos(B));
		name = "Равнобедренный треугольник";
	}
	~IsoscelesTriangle() {}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
	{
		name = "Равносторонний треугольник";
	}
	~EquilateralTriangle() {}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(double a, double b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B)
	{
		name = "Параллелограмм";
	}
	~Parallelogram() {}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double a, double b) : Parallelogram(a, b, 90, 90)
	{
		name = "Прямоугольник";
	}

	~Rectangle() {}
};

class Square : public Rectangle
{
public:
	Square(double a) : Rectangle(a, a)
	{
		name = "Квадрат";
	}
	~Square() {}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double a, double A, double B) : Parallelogram(a, a, A, B)
	{
		name = "Ромб";
	}
	~Rhombus() {}
};

void print_info(Figure* figure) {

	figure->print();
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//	пользователь вводит минимальные данные необходимиые для построения фигур (защита от ввода неверных данных)

	Triangle triangle(10, 20, 30, 50, 60, 60);
	Figure* par_triangle = &triangle;
	print_info(par_triangle);

	RightTriangle right_triangle(10, 20, 30, 50, 60);
	Triangle* par_right_triangle = &right_triangle;
	print_info(par_right_triangle);

	IsoscelesTriangle isosceles_triangle(10, 90);
	Triangle* par_isosceles_triangle = &isosceles_triangle;
	print_info(par_isosceles_triangle);

	EquilateralTriangle equilateral_triangle(100);
	Triangle* par_equilateral_triangle = &equilateral_triangle;
	print_info(par_equilateral_triangle);

	Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* par_quadrilateral = &quadrilateral;
	print_info(par_quadrilateral);

	Rectangle rectangle(10, 20);
	Parallelogram* par_rectangle = &rectangle;
	print_info(par_rectangle);

	Square square(10);
	Rectangle* par_square = &square;
	print_info(par_square);

	Parallelogram parallelogram(10, 30, 40, 50);
	Quadrilateral* par_parallelogram = &parallelogram;
	print_info(par_parallelogram);

	Rhombus rhombus(30, 30, 40);
	Parallelogram* par_rhombus = &rhombus;
	print_info(par_rhombus);

	return 0;
}