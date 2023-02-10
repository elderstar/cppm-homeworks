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

	void virtual print() {
		std::cout << "\n" << getName() << ":";
		if (check()) {
			std::cout << "\n" << "Правильная";
		}
		else {
			std::cout << "\n" << "Неправильная";
		}
		std::cout << "\n" << "Количество сторон: " << side_count;
	}

protected:
	int side_count;
	std::string name;

	bool virtual check() {
		if (side_count > 0) {
			return false;
		}
		else {
			return true;
		}
	}
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
		countSides();
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
		Figure::print();
		std::cout << "\n" << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c();
		std::cout << "\n" << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C();

	}

protected:
	double a, b, c, A, B, C;

	bool check() override
	{
		if (side_count != 3 || (A + B + C) != 180) {
			return false;
		}
		else {
			return true;
		}
	}

	void countSides()
	{
		side_count = 0;
		for (double i : { a, b, c })
		{
			if (i > 0)
				++side_count;
		}
	}
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
		countSides();
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
		Figure::print();
		std::cout << "\n" << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d();
		std::cout << "\n" << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D();
	}

protected:
	double a, b, c, d, A, B, C, D;

	bool check() override
	{
		if (side_count != 4 || (A + B + C + D) != 360) {
			return false;
		}
		else {
			return true;
		}
	}

	void countSides()
	{
		side_count = 0;
		for (double i : { a, b, c, d })
		{
			if (i > 0)
				++side_count;
		}
	}
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		name = "Прямоугольный треугольник";
	}
	~RightTriangle() {}
protected:
	bool check() override
	{
		if (!Triangle::check() || C != 90) {
			return false;
		}
		else {
			return true;
		}
	}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		name = "Равнобедренный треугольник";
	}
	~IsoscelesTriangle() {}
protected:
	bool check() override
	{
		if (!Triangle::check() || A != C || a != c) {
			return false;
		}
		else {
			return true;
		}
	}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		name = "Равносторонний треугольник";
	}
	~EquilateralTriangle() {}
protected:
	bool check() override
	{
		if (!Triangle::check() || A != C || A != B || a != b || a != c) {
			return false;
		}
		else {
			return true;
		}
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrilateral(a, b, c, d, A, B, C, D)
	{
		name = "Параллелограмм";
	}
	~Parallelogram() {}
protected:
	bool check() override
	{
		if (!Quadrilateral::check() || a != c || b != d || A != C || B != D) {
			return false;
		}
		else {
			return true;
		}
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double a, double b, double c, double d, double A, double B, double C, double D) : Parallelogram(a, b, c, d, A, B, C, D)
	{
		name = "Прямоугольник";
	}

	~Rectangle() {}
protected:
	bool check() override
	{
		if (!Parallelogram::check() || A != 90 || B != 90) {
			return false;
		}
		else {
			return true;
		}
	}
};

class Square : public Rectangle
{
public:
	Square(double a, double b, double c, double d, double A, double B, double C, double D) : Rectangle(a, b, c, d, A, B, C, D)
	{
		name = "Квадрат";
	}
	~Square() {}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Parallelogram(a, b, c, d, A, B, C, D)
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

	Figure figure;
	Figure* par_figure = &figure;
	print_info(par_figure);

	Triangle triangle(10, 10, 30, 60, 60, 60);
	Figure* par_triangle = &triangle;
	print_info(par_triangle);

	RightTriangle right_triangle(10, 20, 30, 40, 50, 90);
	Triangle* par_right_triangle = &right_triangle;
	print_info(par_right_triangle);

	IsoscelesTriangle isosceles_triangle(30, 20, 30, 70, 40, 70);
	Triangle* par_isosceles_triangle = &isosceles_triangle;
	print_info(par_isosceles_triangle);

	EquilateralTriangle equilateral_triangle(30, 30, 30, 60, 60, 60);
	Triangle* par_equilateral_triangle = &equilateral_triangle;
	print_info(par_equilateral_triangle);

	Quadrilateral quadrilateral(10, 20, 30, 40, 100, 80, 100, 80);
	Figure* par_quadrilateral = &quadrilateral;
	print_info(par_quadrilateral);

	Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
	Parallelogram* par_rectangle = &rectangle;
	print_info(par_rectangle);

	Square square(20, 20, 20, 20, 90, 90, 90, 90);
	Rectangle* par_square = &square;
	print_info(par_square);

	Parallelogram parallelogram(10, 20, 10, 20, 100, 80, 100, 80);
	Quadrilateral* par_parallelogram = &parallelogram;
	print_info(par_parallelogram);

	Rhombus rhombus(10, 10, 10, 10, 100, 80, 100, 80);
	Parallelogram* par_rhombus = &rhombus;
	print_info(par_rhombus);

	return 0;
}