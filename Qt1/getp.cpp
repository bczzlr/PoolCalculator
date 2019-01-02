//#include"stdafx.h"
#include"circle.h"
#include"square.h"
#include"triangle.h"
//#include<iostream>
//using namespace std;
//extern double Rin;
//extern double Rout;
float getp(int n2,float Rout){
	if(n2==0){
		circle a(Rout);
		return a.perimeter();
	}
	if(n2==1){
		square a(Rout);
		return a.perimeter();
	}
	if(n2==2){
		triangle a(Rout);
		return a.perimeter();
	}
	return 0;
}