#include "linetoitem.h"

#include <QUuid>
#include <QBrush>
#include <QPen>

LineToItem::LineToItem(QGraphicsItem *parent)
: QGraphicsLineItem(parent)
{
	initialize();
}

LineToItem::~LineToItem()
{
  
}


void LineToItem::setColor(const QColor &color){

	_color = color;
}

void LineToItem::setThickness(int thickcness){

	_thickness = thickcness;
}


void LineToItem::initialize()
{
	_color = Qt::black;
	_thickness = 5;
	typeItem = 1;
	SorX = 0;
}



void LineToItem::render()
{
	QLine path;
	path.setLine(SatrtPoint.x(), SatrtPoint.y(), ensdPoint.x(),ensdPoint.y());
	this->setPen(QPen(QBrush(_color), (qreal)_thickness, SorX == 0 ? Qt::SolidLine : Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
	this->setLine(path);
}
