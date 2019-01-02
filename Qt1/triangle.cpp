#include"triangle.h"
#include<math.h>
//extern double Rin,Rout;
float triangle::area(){
	return 1.73/4*length*length;
}
float triangle::perimeter(){
	return 3*length;
}
void triangle::change(double a){
	length=a;
}