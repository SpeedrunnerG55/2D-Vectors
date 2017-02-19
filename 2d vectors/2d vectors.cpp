// 2d vectors.cpp : Defines the entry point for the console application.
//

/*
Julio Rojas, Adam Blakeslee, Douglas Loughmiller, and Beomsoo Kim
Prof. F. Aljamal
CIS 277
14 II 2017
*/

#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <string>


using namespace std;
//container for the vectors. Each struct is one vector
struct Vectors {
	string Title;
	double xaxis;
	double yaxis;
};
struct bounds {
	double yHigh = 0;
	double yLow = 0;
	double xHigh = 0;
	double xLow = 0;
};

//adds preforms vector addition
void Vector_Addition(Vectors v1, Vectors v2);

//preforms vector subtraction
void Vector_Subtraction(Vectors v1, Vectors v2);

//preforms scalar multiplacation
void Scalar_Multiplication(Vectors v1, double k);

//preforms vector multiplacation
void Scalar_Product(Vectors v1, Vectors v2);

//retuens the magnitude or length of the vector
void Vector_Magnitude(Vectors v1);

//gets vector informations
Vectors get_Vector(string name1);

//gets scalar value
double get_Scalar();

//prints vector information
void print_Vector(Vectors Vec1);

//get x and y limmits of vector
bounds getBounds(Vectors V);

//finds gighest value and returns it
double getTop(double a, double b, double c);

//graphical display
void displayVectorOperation(Vectors Vec1, Vectors Vec2, Vectors Vec3);

//inline functions that make GIANT conditionals easier to read.
inline bool limitChecker(int x, double xHigh, double xLow, int y, double yHigh, double yLow);
inline bool cellChecker(float weight, double yValue, int y, double xValue, int x);

/* user interface function responsible for all inputs into vector structs. Also prompts user.
Parameter is to designate the first and second vectors
int Menue_Select; //userinterface variable, only accepts 1-5. Anything else returns error
bool continue; //variable that tells if program is running
*/
int main()
{
	double k = 10;  //variable,used solely as scalar
	Vectors alpha, beta, test;
	char Menu_Select;
	bool running = true;
	do {
		cout << "What do you want to do? type:" << endl;
		cout << "    1 for vector addition." << endl;
		cout << "    2 for vector subtraction." << endl;
		cout << "    3 for scalar multiple." << endl;
		cout << "    4 for scalar product." << endl;
		cout << "    5 for magnitude (length) of a vector.)" << endl;
		cout << "    9 to quit." << endl;
		//Get the type the user want to do for this program
		cin >> Menu_Select;
		switch (Menu_Select)
		{
			case '1':
				alpha = get_Vector("First");
				beta = get_Vector("Second");
				Vector_Addition(alpha, beta);
				break;
			case '2':
				alpha = get_Vector("First");
				beta = get_Vector("Second");
				Vector_Subtraction(alpha, beta);
				break;
			case '3':
				alpha = get_Vector("The");
				k = get_Scalar();
				Scalar_Multiplication(alpha, k);
				break;
			case '4':
				alpha = get_Vector("First");
				beta = get_Vector("Second");
				Scalar_Product(alpha, beta);
				break;
			case '5':
				alpha = get_Vector("The");
				Vector_Magnitude(alpha);
				break;
			case 'T':
				alpha.Title = "Alpha";
				beta.Title = "Beta";
				test.Title = "Test";
				alpha.xaxis = rand() % 30 - 15;
				alpha.yaxis = rand() % 30 - 15;
				beta.xaxis = rand() % 30 - 15;
				beta.yaxis = rand() % 30 - 15;
				test.xaxis = rand() % 30 - 15;
				test.yaxis = rand() % 30 - 15;
				print_Vector(alpha);
				print_Vector(beta);
				print_Vector(test);
				displayVectorOperation(alpha, beta, test);
				break;
			case '9':
				running = false;
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
		}

	} while (running);
	cin.get();
	return 0;
}

Vectors get_Vector(string name) {
	Vectors V;
	cout << "enter " << name << " vector name " << endl;
	cin >> V.Title;
	cout << "enter " << name << " vectors x axis " << endl;
	cin >> V.xaxis;
	cout << "enter " << name << " vectors y axis " << endl;
	cin >> V.yaxis;
	return V;
}

bounds getBounds(Vectors V) {
	bounds B;
	//GET X AXIS LIMMITS
	if (V.xaxis < 0) {
		B.xLow = V.xaxis;
		B.xHigh = 0;
	}
	else if (V.xaxis > 0) {
		B.xLow = 0;
		B.xHigh = V.xaxis;
	}
	//special case if vertical line
	else{
		B.xHigh = 0;
		B.xLow = 0;
	}

	//GET Y AXIS LIMMITS
	if (V.yaxis < 0) {
		B.yLow = V.yaxis;
		B.yHigh = 0;
	}
	else if(V.yaxis > 0) {
		B.yLow = 0;
		B.yHigh = V.yaxis;
	}
	//special case if horizontal line
	else {
		B.yHigh = 0;
		B.yLow = 0;
	}
	return B;
}

double getTop(double a, double b, double c) {

	//defaults to 0 only returns this value if all three vectors have 0 length
	double top = 0;

	//checks the absolute value because values because arguments will be positive or negitive
	if (abs(a) > top) {
		top = abs(a);
	}
	if (abs(b) > top) {
		top = abs(b);
	}
	if (abs(c) > top) {
		top = abs(c);
	}
	return top;
}

//inline functions that make GIANT conditionals easier to read.
inline bool limitChecker(int x, int y, bounds B) {
	return (x <= B.xHigh && x >= B.xLow && y <= B.yHigh && y >= B.yLow);
}

inline bool cellChecker(float weight, double yValue, int y, double xValue, int x) {
	return (yValue > y - weight && yValue < y + weight || xValue > x - weight && xValue < x + weight);
}

//graphical display
void displayVectorOperation(Vectors Vec1, Vectors Vec2, Vectors Vec3) {

	bounds V1B, V2B, V3B;

	//calculates and stores the slope of each vector.
	double M1 = Vec1.yaxis / Vec1.xaxis, M2 = Vec2.yaxis / Vec2.xaxis, M3 = Vec3.yaxis / Vec3.xaxis;
	//variables to store the xy value of the vector at the x,y coodinates
	double yValue1, xValue1, yValue2, xValue2, yValue3, xValue3;
	//variables that store the lowest and highest limmits of each axis for each vector
	int highestY, lowestY, highestX, lowestX;
	//line thickness
	float weight = .6;

	//gets limmits for each vector
	V1B = getBounds(Vec1);
	V2B = getBounds(Vec2);
	V3B = getBounds(Vec3);

	//find highest and lowest value for each limmit to scale the display to fit them all
	highestY = round(getTop(V1B.yHigh, V2B.yHigh, V3B.yHigh));
	lowestY = round(getTop(V1B.yLow, V2B.yLow, V3B.yLow));
	highestX = round(getTop(V1B.xHigh, V2B.xHigh, V3B.xHigh));
	lowestX = round(getTop(V1B.xLow, V2B.xLow, V3B.xLow));

	//display from -10 - 10 for both axix to create a square display sorounding the oragin
	cout << "##";
	for (int x = -lowestX - 2; x < highestX + 3; x++) {
		cout << "=";
	}
	cout << "##" << endl;
	for (int y = highestY + 2; y > -lowestY - 3; y--) {
		cout << "||";
		for (int x = -lowestX - 2; x < highestX + 3; x++) {

			//gets each vectors x y value for the displays x and y value
			yValue1 = M1*x;
			yValue2 = M2*x;
			yValue3 = M3*x;
			xValue1 = y / M1;
			xValue2 = y / M2;
			xValue3 = y / M3;

			/*
			|=============================================== DISPLAY SUMMARY ===============================================|
			|                                                                                                               |
			|                                                                                                               |
			|                                                                                                               |
			|                                                                                                               |
			|  RANGE CHECKER                                                    LIMMIT CHECKER                              |
			|                                                                                                               |
			|  if the Limmit checker for this cell returns true                  each cell will be tested to see if         |
			|  the Range checker will checks the value of the                    it is in within the limmits of the vector  |
			|  linear function of the vector for the x and y axis                                                           |
			|  agenst the range values of the cell                                | for the sake of readability             |
			|                                                                     |  the space around the vector            |
			|          test y range                                               |  is to be auumed false                  |
			|          returns FALSE                                                                                        |
			|                 V                                                                                             |
			| /-------------------------------\                                   |       .                                 |
			| |       **      |               |                                   |       .              F                  |
			| |      **       |               |                                   |       .            FF                   |
			| |      *        |               |                                   |       .          FF                     |
			| |     **        |               |                                   |       .        FF                       |
			| |    **         |               |                                   |       .      FF                         |
			| |----x----------+---------------| < test x range                    |       .    FF                           |
			| |   **          |               |   returns TRUE                    |       .  FF                             |
			| |  **           |               |                                   |       .FF                               |
			| |  *            |               |                                   |------TT---------------< Y Uppert        |
			| | **            |               |                                   |    TT |              Limit              |
			| |**             |               |                                   |  TT   |                                 |
			| \-------------------------------/                                   \TT_____|_______________  __ < Y Lower    |
			|                                                          Origin > O |       ^                      Limmit     |
			|  Range checker will return true if                            FF    ^      X Upper                            |
			|  function values are within at least one ran                FF    X Lower   Limit                             |
			|                                                                     Limit                                     |
			| If the range checker returns true                                                                             |
			| a marker will be plotted on the cell                                will return TRUE if within the limits     |
			|=============================================== DISPLAY SUMMARY ===============================================|
			*/

			//display oragin
			if (y == 0 && x == 0) {
				cout << "#";
			}

			//if the y value of the linear function is whithin range display its ID (the first character of their title)

			//Vector 1

			//Limit checker
			else if (limitChecker(x,y,V1B) && cellChecker(weight, yValue1, y, xValue1, x)){
				//plot marker
				cout << Vec1.Title[0];
			}

			//Vector 2

			//Limit checker
			else if (limitChecker(x,y,V2B) && cellChecker(weight, yValue2, y, xValue2, x)){
				//plot marker
				cout << Vec2.Title[0];
			}

			//Vector 3

			//Limit checker
			else if (limitChecker(x,y,V3B) && cellChecker(weight, yValue3, y, xValue3, x)){
				//plot marker
				cout << Vec3.Title[0];
			}

			//Display Y axis
			else if (x == 0) {
				cout << "|";
			}

			//Display X axis
			else if (y == 0) {
				cout << "-";
			}

			//displlay nothing
			else {
				cout << " ";
			}

		}
		cout << "||" << endl;
	}
	cout << "##";
	for (int x = -lowestX - 2; x < highestX + 3; x++) {
		cout << "=";
	}
	cout << "##" << endl;
}

double get_Scalar() {
	double scalar;
	cout << "enter Scalar value" << endl;
	cin >> scalar;
	return scalar;
}

void print_Vector(Vectors Vec1) {
	cout << setprecision(2) << fixed << setw(20) << left << Vec1.Title << "(" << Vec1.xaxis << "," << Vec1.yaxis << ")" << endl;
}

void print_Scalar(double k) {
	cout << setprecision(2) << fixed << setw(20) << left << "Scalar:" << k << endl;
}

void Vector_Addition(Vectors vec1, Vectors vec2) {
	Vectors sum;
	sum.xaxis = vec1.xaxis + vec2.xaxis;
	sum.yaxis = vec1.yaxis + vec2.yaxis;
	//set title for output vector
	sum.Title = "sum";
	//input vectors
	print_Vector(vec1);
	print_Vector(vec2);
	//output vector
	print_Vector(sum);
	displayVectorOperation(vec1, vec2, sum);
}

void Vector_Subtraction(Vectors alpha, Vectors beta) {
	Vectors diff;
	//set title for output vector
	diff.Title = "Difference";
	diff.xaxis = alpha.xaxis - beta.xaxis;
	diff.yaxis = alpha.yaxis - beta.yaxis;
	//input vectors
	print_Vector(alpha);
	print_Vector(beta);
	//output vector
	print_Vector(diff);
	displayVectorOperation(alpha, beta, diff);
}

void Scalar_Multiplication(Vectors vec1, double k) {
	Vectors mult;
	//set title for output vector
	mult.Title = "multiple";
	mult.xaxis = vec1.xaxis*k;
	mult.yaxis = vec1.yaxis*k;
	//input Vector
	print_Vector(vec1);
	//input scalor
	print_Scalar(k);
	//output vector
	print_Vector(mult);
	//overlap the first vecttor because function must take 3 vectors
	displayVectorOperation(vec1, vec1, mult);
}


void Scalar_Product(Vectors vec1, Vectors vec2) {
	//input vectors
	print_Vector(vec1);
	print_Vector(vec2);
	//output scalar
	cout << "Scalar Product" << endl;
	print_Scalar(vec1.xaxis*vec2.xaxis + vec1.yaxis*vec2.yaxis);
	displayVectorOperation(vec1, vec1, vec2);
}


void Vector_Magnitude(Vectors vec1) {
	//input vector
	print_Vector(vec1);
	//output scalar
	cout << "Magnitude" << endl;
	print_Scalar(sqrt(pow(vec1.xaxis, 2) + pow(vec1.yaxis, 2)));
	displayVectorOperation(vec1, vec1, vec1);
}
