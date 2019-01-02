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
		ui.btnShow,  //a����
		SIGNAL(clicked(bool)),//a���ź�
		this,//b����
		SLOT(OnShowClicked(bool))//b�Ĳ�
		
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
	fout<<"��������Ԥ��Ϊ"<<budget<<"Ԫ."<<endl;
	fout<<"Χ����״Ϊ��"<<soutshape<<endl;
	fout<<"Χ���Ĳ����ǣ�"<<outpara<<endl;
	fout<<"Ӿ����״Ϊ��"<<sinshape<<endl;
	fout<<"Ӿ�ز���Ϊ��"<<inpara<<endl;
	fout<<"��ƺ�ȼ�Ϊ��"<<sgrasslevel<<endl;
	fout<<"Ӿ�صȼ�Ϊ��"<<spoollevel<<endl;
	int num1,num2;
	if(outshape=="Բ��")num1=0;
	if(outshape=="������")num1=1;
	if(outshape=="������")num1=2;
	if(inshape=="Բ��")num2=0;
	if(inshape=="������")num2=1;
	if(inshape=="������")num2=2;

	float area=0;
	float parameter=0;
	float money;

	int p;
	if(poorlevel=="����") p=0;
	if(poorlevel=="��ͨ") p=1;
	if(poorlevel=="�߶�") p=2;

	int g;
	if(grasslevel=="����") g=0;
	if(grasslevel=="��ͨ") g=1;
	if(grasslevel=="�߶�") g=2;

	if(judge(num1,outpara,num2,inpara)==0)
	{
		ui.textEdit->setText("Ӿ���������Χ��Χ��ס��");
		fout<<"Ӿ���������Χ��Χ��ס��"<<endl;
		return 0;
	}

	if(budget==0)//����Ԥ��
	{
		money=geta(num2,inpara)*poolprice(p)+getp(num1,outpara)*fence+grassprice(g)*(geta(num1,outpara)-geta(num2,inpara));
		ui.textEdit->setText("������Ԥ�������£��ܹ�����"+QString::number(money)+"Ԫ��");
		fout<<"������Ԥ�������£��ܹ�����"<<money<<"Ԫ."<<endl;
	}
	else 
	{
		money=geta(num2,inpara)*poolprice(p)+getp(num1,outpara)*fence+grassprice(g)*(geta(num1,outpara)-geta(num2,inpara));
		if((budget-money)>=0)
		{
			ui.textEdit->setText("Ԥ����㣬�ѻ���"+QString::number(money)+"Ԫ����ʣ"+QString::number(budget-money)+"Ԫ��");
			fout<<"Ԥ����㣬�ѻ���"<<money<<"Ԫ����ʣ"<<budget-money<<"Ԫ."<<endl;
		}
		else
		{ui.textEdit->setText("Ԥ�㲻�㣬����"+QString::number(fabs(budget-money))+"Ԫ��");
		fout<<"Ԥ�㲻�㣬����"<<fabs(budget-money)<<"Ԫ��"<<endl;
		}
	}
	fout<<"============================================"<<endl;
	return 0;
}
 