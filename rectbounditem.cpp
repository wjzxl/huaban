#include "rectbounditem.h"
#include <QUuid>
#include <QBrush>
#include <QPen>

rectboundItem::rectboundItem(QGraphicsItem *parent)
: QGraphicsRectItem(parent)
{
	initialize();
}

rectboundItem::~rectboundItem()
{

}


void rectboundItem::setColor(const QColor &color){

	_color = color;
}

void rectboundItem::setThickness(int thickcness){

	_thickness = thickcness;
}


void rectboundItem::initialize()
{
	_color = Qt::black;
	_thickness = 5;
	typeItem = 2;
	SorX = 0;
}



void rectboundItem::render()
{

	QPointF stagdf = SatrtPoint;
	/*if ((ensdPoint.x() - SatrtPoint.x()) < 0 && (ensdPoint.y() - SatrtPoint.y()) < 0){
		stagdf.setX(SatrtPoint.x()-ensdPoint.x());
		stagdf.setY(SatrtPoint.y()-ensdPoint.y());
	}
	else if ((ensdPoint.x() - SatrtPoint.x()) < 0 && (ensdPoint.y() - SatrtPoint.y()) >= 0){
		stagdf.setX(SatrtPoint.x() - ensdPoint.x());
	}
	else if ((ensdPoint.x() - SatrtPoint.x()) >= 0 && (ensdPoint.y() - SatrtPoint.y()) < 0){
		stagdf.setY(SatrtPoint.y() - ensdPoint.y());
	}*/

	/*QRectF linshiRectF = QRectF(SatrtPoint, ensdPoint);

	if ((ensdPoint.x() - SatrtPoint.x()) < 0 || (ensdPoint.y() - SatrtPoint.y()) < 0){
		linshiRectF = QRectF(ensdPoint, SatrtPoint);
	}*/

	QRectF path;
	//path = QRectF(linshiRectF);

	//path.setRect(stagdf.x(), stagdf.y(), ensdPoint.x() - SatrtPoint.x(), ensdPoint.y()-SatrtPoint.y());
	path.setRect(stagdf.x(), stagdf.y(), fabs(ensdPoint.x() - SatrtPoint.x()), fabs(ensdPoint.y() - SatrtPoint.y()));
	this->setPen(QPen(QBrush(_color), (qreal)_thickness, SorX == 0 ? Qt::SolidLine : Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
	this->setRect(path);
}