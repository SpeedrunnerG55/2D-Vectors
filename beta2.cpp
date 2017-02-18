#include "math.h"
#include "stdio.h"
#include "iomanip"
#include "iostream"
using namespace std;
struct Vectors{
	string name;
	double xaxis;
	double yaxis;
};
//container for the vectors. Each struct is one vector
void Vector_Addition (Vectors v1, Vectors v2);
void Vector_Subtraction (Vectors v1, Vectors v2);
void Scalar_Multiplication (Vectors v1, float k);
void Scalar_Product (Vectors v1, Vectors v2);
void Vector_Magnitude (Vectors v1);
Vectors get_Vector(string name1);
void print_Vector(Vectors Vec1);

/* user interface function responsible for all inputs into vector structs. Also prompts user.
Parameter is to designate the first and second vectors
int Menue_Select; //userinterface variable, only accepts 1-5. Anything else returns error
bool continue; //variable that tells if program is running
*/
int main()
{
	float k = 10;  //variable,used solely as scalar
	Vectors alpha, beta;
	char Menu_Select;
	alpha.name   = "name1";
	alpha.xaxis  = 8;
	alpha.yaxis  = -3;
	beta.name    = "name2";
	beta.xaxis   = 10;
	beta.yaxis   = 5;
	bool running = true;
	do{
		cout << "What do you want to do? type:" << endl;
		cout << "    1 for vector addition." << endl;
		cout << "    2 for vector subtraction." << endl;
		cout << "    3 for scalar multiple." << endl;
		cout << "    4 for scalar product." << endl;
		cout << "    5 for magnitude (length) of a vector.)" << endl;
		cout << "    9 to quit." << endl;
		//Get the type the user want to do for this program
		cin >> Menu_Select;
		switch(Menu_Select)
		{
			case '1':
				Vector_Addition(alpha,beta);
				break;
			case '2':
				Vector_Subtraction(alpha,beta);
				break;
			case '3':
				Scalar_Multiplication(alpha,k);
				break;
			case '4':
				Scalar_Product(alpha,beta);
				break;
			case '5':
				Vector_Magnitude(alpha);
				break;
			case '9':
				running = false;
	      break;
			default :
			  cout << "Invalid Input" << endl;
				break;
		}

	}while(running);
	cin.get();
	return 0;
}
Vectors get_Vector(string name){
	Vectors vec1;
	cout << "enter " << name << " vector name " << endl;
	cin >> vec1.name;
	cout << "enter " << name << " vectors x axis " << endl;
	cin >> vec1.xaxis;
	cout << "enter " << name << " vectors y axis " << endl;
	cin >> vec1.yaxis;
	return vec1;
}
void print_Vector(Vectors Vec1){
	cout << setprecision(2) << fixed << setw(20) << left << Vec1.name << "(" << Vec1.xaxis << "," << Vec1.yaxis << ")" << endl;
}
void print_Scalar(float k){
	cout << setprecision(2) << fixed << setw(20) << left << "Scalar:" << k << endl;
}
void Vector_Addition(Vectors vec1, Vectors vec2){ /*function definition for vector addition. Needs no parameters as output is included within*/
	Vectors sum;
	sum.xaxis = vec1.xaxis + vec2.xaxis;
	sum.yaxis = vec1.yaxis + vec2.yaxis;
	sum.name  = "sum";
	print_Vector(vec1);
	print_Vector(vec2);
	print_Vector(sum);
}
void Vector_Subtraction(Vectors alpha, Vectors beta){ /*function definition for vector subtraction. Needs no parameters as output is included within*/
	Vectors diff;
	diff.name  = "Difference";
	diff.xaxis = alpha.xaxis-beta.xaxis;
	diff.yaxis = alpha.yaxis-beta.yaxis;
	print_Vector(alpha);
	print_Vector(beta);
	print_Vector(diff);
}
void Scalar_Multiplication(Vectors vec1, float k){
	Vectors mult;
	mult.name  = "Scalar multiple";
	mult.xaxis = vec1.xaxis*k;
	mult.yaxis = vec1.yaxis*k;
	print_Vector(vec1);
	print_Scalar(k);
	print_Vector(mult);
}
void Scalar_Product(Vectors vec1, Vectors vec2) {
	print_Vector(vec1);
	print_Vector(vec2);
	cout << "Scalar Product" << endl;
	print_Scalar(vec1.xaxis*vec2.xaxis + vec1.yaxis*vec2.yaxis);
}
void Vector_Magnitude(Vectors vec1){/*note that scalar K is the solution variable here*/
	print_Vector(vec1);
	cout << "Magnitude" << endl;
	print_Scalar(sqrt(pow(vec1.xaxis,2) + pow(vec1.yaxis,2)));
}

