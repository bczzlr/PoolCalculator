
#include <math.h>

int judge(int num1,float Rout,int num2,float Rin){
	if(num1==num2){
		if(Rin>Rout) return 0;
		else return 1;
	}
	else{
		if(num1==0){
			if(num2==1){
				if(Rout<Rin/sqrt(2.0)) return 0;
				else return 1;
			}
			if(num2==2){
				if(Rout<Rin/sqrt(3.0)) return 0;
				else return 1;
			}

		}
		if(num1==1){
			if(num2==2){
				if(1.035*Rout<Rin) return 0;
				else return 1;
			}
			if(num2==0){
				if(Rout<2*Rin) return 0;
				else return 1;
			}
		}
		if(num1==2){
			if(num2==0){
				if(0.288*Rout<Rin) return 0;
				else return 1;
			}
			if(num2==1){
				if(0.464*Rout<Rin) return 0;
				else return 1;
			}
		}

	}
	return 0;
}