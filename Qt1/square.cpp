#include"square.h"
//extern double Rin,Rout;
float square::perimeter()
{
	return 4*length;
}
float square::area(){
	return length*length;
}
void square::change(double a){
	length=a;
}