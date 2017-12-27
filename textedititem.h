#ifndef TEXTEDITITEM_H
#define TEXTEDITITEM_H

#include <QObject> 
#include <QGraphicsTextItem>
#include <QPointF>

class TexteditItem : public QObject, public QGraphicsTextItem
{
	Q_OBJECT

public:
	TexteditItem(QGraphicsItem *parent =0);
	~TexteditItem();
	QRectF boundingRect() const; //这个函数是vitual必须重新实现，否则所定义的类难以实例化?
	 
	void setColor(const QColor& color);
	void setThickness(int thickcness);

	QColor _color;
	int _thickness;
	int typeItem;
	int SorX;

	QRectF poiboundRect;

	void render(void);

	QPointF SatrtPoint;
    
	float WidthS;
	QString contentStr;

private:

	void initialize(void);
	
};

#endif // TEXTEDITITEM_H
