#ifndef OBJITEM_H
#define OBJITEM_H

#include <QObject>
#include <QGraphicsPathItem>
#include <vector>
#include <QPointF>
#include <QPainter>
#include <QLabel>
#include <QPointer>

class ObjItem : public QGraphicsPathItem
{

public:
	ObjItem(QGraphicsItem* parent = 0);
	void setColor(const QColor& color);
	void setThickness(int thickcness);

	QColor _color;
	int _thickness;
	int typeItem;
	int SorX;
	void render(void);

	std::vector<QPointF> points(void){ return this->_listPoints; }
	void addPoint(const QPointF& pt){
		this->_listPoints.push_back(pt);
	}

private:
	std::vector<QPointF> _listPoints;

	void initialize(void);
};

#endif // OBJITEM_H
