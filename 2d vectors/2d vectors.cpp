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

struct Vectors {
	string Title;
	double xaxis;
	double yaxis;
};
//container for the vectors. Each struct is one vector

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

/* user interface function responsible for all inputs into vector structs. Also prompts user.
Parameter is to designate the first and second vectors
int Menue_Select; //userinterface variable, only accepts 1-5. Anything else returns error
bool continue; //variable that tells if program is running
*/
int main()
{
	double k = 10;  //variable,used solely as scalar
	Vectors alpha, beta;
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
	Vectors vec1;
	cout << "enter " << name << " vector name " << endl;
	cin >> vec1.Title;
	cout << "enter " << name << " vectors x axis " << endl;
	cin >> vec1.xaxis;
	cout << "enter " << name << " vectors y axis " << endl;
	cin >> vec1.yaxis;
	return vec1;
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
}

void Scalar_Multiplication(Vectors vec1, double k) {
	Vectors mult;
	//set title for output vector
	mult.Title = "Scalar multiple";
	mult.xaxis = vec1.xaxis*k;
	mult.yaxis = vec1.yaxis*k;
	print_Vector(vec1);
	print_Scalar(k);
	//output vector
	print_Vector(mult);
}


void Scalar_Product(Vectors vec1, Vectors vec2) {
	print_Vector(vec1);
	print_Vector(vec2);
	//output scalar
	cout << "Scalar Product" << endl;
	print_Scalar(vec1.xaxis*vec2.xaxis + vec1.yaxis*vec2.yaxis);
}


void Vector_Magnitude(Vectors vec1) {
	print_Vector(vec1);
	//output scalar
	cout << "Magnitude" << endl;
	print_Scalar(sqrt(pow(vec1.xaxis, 2) + pow(vec1.yaxis, 2)));
}
