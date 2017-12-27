#ifndef CIRCLEITEM_H
#define CIRCLEITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QPointF>

class CircleItem : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

public:
	CircleItem(QGraphicsItem* parent = 0);
	~CircleItem();

	void setColor(const QColor& color);
	void setThickness(int thickcness);

	QColor _color;
	int _thickness;
	int typeItem;
	int SorX;
	void render(void);

	QPointF SatrtPoint;
	QPointF ensdPoint;

private:

	void initialize(void);
	
};

#endif // CIRCLEITEM_H
