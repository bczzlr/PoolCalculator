#include"circle.h"
//extern double Rin,Rout;
#define pi 3.14
float circle::area(){
	return radious*radious*pi;
}
float circle::perimeter(){
	return 2*pi*radious;
}
void circle::change(double a){
	radious=a;
}