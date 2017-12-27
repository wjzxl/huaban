#ifndef MYSELFITEM_H
#define MYSELFITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <vector>
#include <QPointF>
#include <QPainter>
#include <QRectF>
#include <QPointer>
#include <QGraphicsScene>

# pragma execution_character_set("utf-8")

class MySelfItem : public QObject,public QGraphicsItem
{
	Q_OBJECT

public:
	MySelfItem();
	~MySelfItem();
	QRectF boundingRect() const; //这个函数是vitual必须重新实现，否则所定义的类难以实例化 

	int typeItem;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	//void timerEvent(QTimerEvent *);////重新实现timeEvent这个函数，定时器的作用  
	
};

#endif // MYSELFITEM_H
