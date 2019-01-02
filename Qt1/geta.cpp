//#include"stdafx.h"
#include"circle.h"
#include"square.h"
#include"triangle.h"
//#include<iostream>
//using namespace std;
float geta(int n2,float r){
	if(n2==0){
		circle a(r);
		return a.area();
	}
	if(n2==1){
		square a(r);
		return a.area();
	}
	if(n2==2){
		triangle a(r);
		return a.area();
	}

}