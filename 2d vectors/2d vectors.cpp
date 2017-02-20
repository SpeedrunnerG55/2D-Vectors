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
//stores the bounds of the vecotr
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
bounds get_Bounds(Vectors V);

//finds gighest value and returns it
double get_Top(double a, double b, double c);

//graphical display
void displayVectorOperation(Vectors v1);
void displayVectorOperation(Vectors v1, Vectors v2);
void displayVectorOperation(Vectors v1, Vectors v2, Vectors v3);
void displayVectorOperation(Vectors v1, Vectors v2, Vectors v3, Vectors v4);
template<int arrayLength>
void displayVectorOperation(Vectors(&Vecs)[arrayLength]);

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
	Vectors Alpha, Beta, Delta, Gamma;
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
				Alpha = get_Vector("First");
				Beta = get_Vector("Second");
				Vector_Addition(Alpha, Beta);
				break;
			case '2':
				Alpha = get_Vector("First");
				Beta = get_Vector("Second");
				Vector_Subtraction(Alpha, Beta);
				break;
			case '3':
				Alpha = get_Vector("The");
				k = get_Scalar();
				Scalar_Multiplication(Alpha, k);
				break;
			case '4':
				Alpha = get_Vector("First");
				Beta = get_Vector("Second");
				Scalar_Product(Alpha, Beta);
				break;
			case '5':
				Alpha = get_Vector("The");
				Vector_Magnitude(Alpha);
				break;
			case 'T':
				Alpha.Title = "Alpha";
				Beta.Title = "Beta";
				Delta.Title = "Delta";
				Gamma.Title = "Gamma";
				Alpha.xaxis = rand() % 40 - 20;
				Alpha.yaxis = rand() % 40 - 20;
				Beta.xaxis = rand() % 40 - 20;
				Beta.yaxis = rand() % 40 - 20;
				Delta.xaxis = rand() % 40 - 20;
				Delta.yaxis = rand() % 40 - 20;
				Gamma.xaxis = rand() % 40 - 20;
				Gamma.yaxis = rand() % 40 - 20;
				print_Vector(Alpha);
				print_Vector(Beta);
				print_Vector(Delta);
				print_Vector(Gamma);
				displayVectorOperation(Alpha, Beta, Delta, Gamma);
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

bounds get_Bounds(Vectors V) {
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

//inline functions that make GIANT conditionals easier to read.
inline bool limitChecker(int x, int y, bounds B) {
	return (x <= B.xHigh && x >= B.xLow && y <= B.yHigh && y >= B.yLow);
}

inline bool cellChecker(float weight, double yValue, int y, double xValue, int x) {
	return (yValue > y - weight && yValue < y + weight || xValue > x - weight && xValue < x + weight);
}

void displayVectorOperation(Vectors v1)
{
	Vectors vecs[1] = { v1 };
	displayVectorOperation(vecs);
}

void displayVectorOperation(Vectors v1, Vectors v2)
{
	Vectors vecs[2] = { v1, v2 };
	displayVectorOperation(vecs);
}

void displayVectorOperation(Vectors v1, Vectors v2, Vectors v3)
{
	Vectors vecs[3] = { v1, v2, v3 };
	displayVectorOperation(vecs);
}

void displayVectorOperation(Vectors v1, Vectors v2, Vectors v3, Vectors v4)
{
	Vectors vecs[4] = { v1, v2, v3, v4 };
	displayVectorOperation(vecs);
}

//graphical display
template<int arrayLength>
void displayVectorOperation(Vectors(&Vecs)[arrayLength]) {

	//Plausibly display something in this case?
	if (arrayLength == 0) {
		cout << "Error! Array Length of 0!\n\n";
		return;
	}

	//stores the bounds of the vecotr
	bounds VB[arrayLength];

	//Arrays of storage, sized to the length of Vecs
	double* M = new double[arrayLength];
	double* xValue = new double[arrayLength];
	double* yValue = new double[arrayLength];
	double* xLow = new double[arrayLength];
	double* yLow = new double[arrayLength];
	double* xHigh = new double[arrayLength];
	double* yHigh = new double[arrayLength];
		
	//initial values set to the opposite extremes. To ensure it's accurracy, despite the input.
	double highestY = -DBL_MAX;
	double lowestY = DBL_MAX;
	double highestX = -DBL_MAX;
	double lowestX = DBL_MAX;

	//line thickness
	float weight = .6;

	//grid line spacing
	int grid = 5;

	for (int i = 0; i < arrayLength; i++){

		//calculates and stores the slope of each vector. 
		M[i] = Vecs[i].yaxis / Vecs[i].xaxis;

		//gets limmits for each vector
		VB[i] = get_Bounds(Vecs[i]);

		//find highest and lowest value for each limmit to scale the display to fit them all
		if (VB[i].yHigh > highestY)highestY = VB[i].yHigh;
		if (VB[i].yLow < lowestY)lowestY = VB[i].yLow;
		if (VB[i].xHigh > highestX)highestX = VB[i].xHigh;
		if (VB[i].xLow < lowestX)lowestX = VB[i].xLow;
	}

	//display from Lowest to highest to fit all lines

	//Top border and corners
	cout << "##";
	for (int x = lowestX - 2; x < highestX + 3; x++) {
		cout << "=";
	}
	cout << "##" << endl;

	//inside
	for (int y = highestY + 2; y > lowestY - 3; y--) {
		//left border
		cout << "||";
		for (int x = lowestX - 2; x < highestX + 3; x++) {			

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

			else {
				//Since checking an array, you have to have a variable outside to determine if something was found
				bool found = false;
				for (int i = 0; i < arrayLength && !found; i++)
				{
						//Limit checker
					if (limitChecker(x, y, VB[i])) {
						//gets each vectors x y value for the displays x and y value
						yValue[i] = M[i] * x;
						xValue[i] = y / M[i];
						if (cellChecker(weight, yValue[i], y, xValue[i], x)){
							found = true;
							//plot marker
							cout << Vecs[i].Title[0];
						}
					}
				}

				//Nothing found? Spread out.
				if (!found) {

					//Display Y axis
					if (x == 0) {
						cout << "|";
					}

					//Display X axis
					else if (y == 0) {
						cout << "-";
					}
					 
					else if (y % grid == 0 && x % grid == 0) {
						cout << "+";
					}

					else if(x % grid == 0){
						cout << ".";
					}					

					else if (y % grid == 0) {
						cout << ".";
					}

					//displlay nothing
					else {
						cout << " ";
					}
				}
			}
		}
		//right border and Y grid marker
		cout << "|| "; if (y % grid == 0) cout << y << endl;
		else{
			cout << endl;
		}
	}
	//Bottom border and corners
	cout << "##";
	for (int x = lowestX - 2; x < highestX + 3; x++) {
		cout << "=";
	}
	cout << "##" << endl;
	cout << "  ";

	//X grid markers
	bool afterfirst = false;
	for (int x = lowestX - 2; x < highestX + 3; x++) {
		if (x % grid == 0) {
			afterfirst = true;
			cout << setw(grid) << x;
		}
		if (!afterfirst) cout << " ";
	}

	cout << endl;

	delete[] M;
	delete[] xValue;
	delete[] yValue;
	delete[] xLow;
	delete[] yLow;
	delete[] xHigh;
	delete[] yHigh;
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
	displayVectorOperation(vec1, mult);
}


void Scalar_Product(Vectors vec1, Vectors vec2) {
	//input vectors
	print_Vector(vec1);
	print_Vector(vec2);
	//output scalar
	cout << "Scalar Product" << endl;
	print_Scalar(vec1.xaxis*vec2.xaxis + vec1.yaxis*vec2.yaxis);
	displayVectorOperation(vec1, vec2);
}


void Vector_Magnitude(Vectors vec1) {
	//input vector
	print_Vector(vec1);
	//output scalar
	cout << "Magnitude" << endl;
	print_Scalar(sqrt(pow(vec1.xaxis, 2) + pow(vec1.yaxis, 2)));
	displayVectorOperation(vec1);
}
