#ifndef QT1_H
#define QT1_H

#include <QtGui/QMainWindow>
#include "ui_qt1.h"


class Qt1 : public QMainWindow
{
	Q_OBJECT

public:
	Qt1(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Qt1();

private slots:
	int OnShowClicked(bool checked);
private:
	Ui::Qt1Class ui;
};

#endif // QT1_H
