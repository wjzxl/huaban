#ifndef MYLABSHOW_H
#define MYLABSHOW_H

#include <QPointer>
#include <QGraphicsScene>
#include <QWidget>
#include <QLabel>
#include <QScrollArea>

class mylabshow :public QScrollArea
{
public:
	mylabshow(QWidget *parent = 0);
	~mylabshow();

public:
	//void scrolltoThebottom();//¹ö¶¯µ½µ×²¿
	//QLabel *namtalbe;
};

#endif