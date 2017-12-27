#ifndef LINETOITEM_H
#define LINETOITEM_H

#include <QObject>
#include <QGraphicsLineItem>
#include <QPointF>

class LineToItem : public QObject, public QGraphicsLineItem
{
	Q_OBJECT

public:
	LineToItem(QGraphicsItem* parent = 0);
	~LineToItem();

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

#endif // LINETOITEM_H
