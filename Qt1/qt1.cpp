#include "qt1.h"
#include <string>
#include <fstream>
#define fence 7
#include <math.h>
#define  poolh 40
#define  poolm 30
#define  pooll 20
#define  grassh 7
#define  grassm 6
#define  grassl 5
#include "circle.h"
#include "square.h"
#include "triangle.h"
using namespace std;
float geta(int n2,float r);
float getp(int n2,float Rout);
int poolprice(int p);
int grassprice(int g);

int judge(int num1,float Rout,int num2,float Rin);

Qt1::Qt1(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	connect (
		ui.btnShow,  //a对象
		SIGNAL(clicked(bool)),//a的信号
		this,//b对象
		SLOT(OnShowClicked(bool))//b的槽
		
		);
}

Qt1::~Qt1()
{

}

int Qt1::OnShowClicked(bool checked)
{
	float budget=ui.budgetlineEdit->text().toFloat();
	QString outshape=ui.outshapelineEdit->text();
	float outpara=ui.outparalineEdit->text().toFloat();
	QString inshape=ui.inshapelineEdit->text();
	float inpara=ui.inparalineEdit->text().toFloat();
	QString poorlevel=ui.poorlevellineEdit->text();
	QString grasslevel=ui.grasslevellineEdit->text();
	ofstream fout;
	fout.open("qt1.txt",ios::out|ios::app);
	string soutshape=outshape.toStdString();
	string sinshape=inshape.toStdString();
	string sgrasslevel=grasslevel.toStdString();
	string spoollevel=poorlevel.toStdString();
	fout<<"本次输入预算为"<<budget<<"元."<<endl;
	fout<<"围栏形状为："<<soutshape<<endl;
	fout<<"围栏的参数是："<<outpara<<endl;
	fout<<"泳池形状为："<<sinshape<<endl;
	fout<<"泳池参数为："<<inpara<<endl;
	fout<<"草坪等级为："<<sgrasslevel<<endl;
	fout<<"泳池等级为："<<spoollevel<<endl;
	int num1,num2;
	if(outshape=="圆形")num1=0;
	if(outshape=="正方形")num1=1;
	if(outshape=="三角形")num1=2;
	if(inshape=="圆形")num2=0;
	if(inshape=="正方形")num2=1;
	if(inshape=="三角形")num2=2;

	float area=0;
	float parameter=0;
	float money;

	int p;
	if(poorlevel=="简易") p=0;
	if(poorlevel=="普通") p=1;
	if(poorlevel=="高端") p=2;

	int g;
	if(grasslevel=="简易") g=0;
	if(grasslevel=="普通") g=1;
	if(grasslevel=="高端") g=2;

	if(judge(num1,outpara,num2,inpara)==0)
	{
		ui.textEdit->setText("泳池面积过大，围栏围不住。");
		fout<<"泳池面积过大，围栏围不住。"<<endl;
		return 0;
	}

	if(budget==0)//无限预算
	{
		money=geta(num2,inpara)*poolprice(p)+getp(num1,outpara)*fence+grassprice(g)*(geta(num1,outpara)-geta(num2,inpara));
		ui.textEdit->setText("在无限预算的情况下，总共花费"+QString::number(money)+"元。");
		fout<<"在无限预算的情况下，总共花费"<<money<<"元."<<endl;
	}
	else 
	{
		money=geta(num2,inpara)*poolprice(p)+getp(num1,outpara)*fence+grassprice(g)*(geta(num1,outpara)-geta(num2,inpara));
		if((budget-money)>=0)
		{
			ui.textEdit->setText("预算充足，已花费"+QString::number(money)+"元，还剩"+QString::number(budget-money)+"元。");
			fout<<"预算充足，已花费"<<money<<"元，还剩"<<budget-money<<"元."<<endl;
		}
		else
		{ui.textEdit->setText("预算不足，还需"+QString::number(fabs(budget-money))+"元。");
		fout<<"预算不足，还需"<<fabs(budget-money)<<"元。"<<endl;
		}
	}
	fout<<"============================================"<<endl;
	return 0;
}
 