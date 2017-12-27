#include "circleitem.h"

#include <QUuid>
#include <QBrush>
#include <QPen>

CircleItem::CircleItem(QGraphicsItem *parent)
	: QGraphicsEllipseItem(parent)
{
	initialize();
}

CircleItem::~CircleItem()
{

}

void CircleItem::setColor(const QColor &color){

	_color = color;
}

void CircleItem::setThickness(int thickcness){

	_thickness = thickcness;
}


void CircleItem::initialize()
{
	_color = Qt::black;
	_thickness = 5;
	typeItem = 3;
	SorX = 0;
}



void CircleItem::render()
{


	int widhfh = fabs(ensdPoint.x() - SatrtPoint.x());
	int heightdd = fabs(ensdPoint.y() - SatrtPoint.y());

	double x = SatrtPoint.x() - (double(widhfh) / 2.f);
	

	double y = SatrtPoint.y() - (double(heightdd) / 2.f);
	
	QRectF path;
	path.setRect(x, y, widhfh, heightdd);
	this->setPen(QPen(QBrush(_color), (qreal)_thickness, SorX == 0 ? Qt::SolidLine : Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
	this->setRect(path);
}
