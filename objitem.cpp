#include "objitem.h"

#include <QUuid>
#include <QBrush>
#include <QPen>

ObjItem::ObjItem(QGraphicsItem *parent)
: QGraphicsPathItem(parent)
{
	initialize();
}



void ObjItem::setColor(const QColor &color){

	_color = color;
}

void ObjItem::setThickness(int thickcness){

	_thickness = thickcness;
}


void ObjItem::initialize()
{
	_color = Qt::black;
	_thickness = 3;
	typeItem = 0;
}



void ObjItem::render()
{
	if (this->_listPoints.size() < 1) return;

	QPainterPath path;
	path.moveTo(this->_listPoints[0]);
	for (size_t i = 1; i < this->_listPoints.size(); i++){
		path.lineTo(this->_listPoints[i]);
	}

	this->setPen(QPen(QBrush(_color), (qreal)_thickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	this->setPath(path);
}
