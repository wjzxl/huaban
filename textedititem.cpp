#include "textedititem.h"
#include <QUuid>
#include <QBrush>
#include <QPen>
#include <QFont>


TexteditItem::TexteditItem(QGraphicsItem *parent)
	: QGraphicsTextItem(parent)
{
	initialize();
}

TexteditItem::~TexteditItem()
{

}

void TexteditItem::setColor(const QColor &color){

	_color = color;
}

void TexteditItem::setThickness(int thickcness){

	_thickness = thickcness;
}


void TexteditItem::initialize()
{
	_color = Qt::black;
	_thickness = 5;
	typeItem = 5;
	SorX = 0;
}



QRectF TexteditItem::boundingRect() const{
	return  poiboundRect;
}

void TexteditItem::render()
{
	this->setFont(QFont("ËÎÌו", _thickness, QFont::Normal));
	this->setColor(_color);
	this->setPos(SatrtPoint);
	this->setTextWidth(WidthS);
	this->setPlainText(contentStr);
	this->setTextInteractionFlags(Qt::NoTextInteraction);
	this->boundingRect();
	printf("== %f   == %f",this->textWidth(), this->boundingRect().height());
	//this->adjustSize();
}
