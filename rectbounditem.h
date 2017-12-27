#ifndef RECTBOUNDITEM_H
#define RECTBOUNDITEM_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPointF>

class rectboundItem : public QObject,public QGraphicsRectItem
{
	Q_OBJECT

public:
	rectboundItem(QGraphicsItem* parent = 0);
	~rectboundItem();

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

#endif // RECTBOUNDITEM_H
