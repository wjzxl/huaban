#include "myselfitem.h"

MySelfItem::MySelfItem()
{
	//setFlag(ItemIsMovable);//可以移动

}

MySelfItem::~MySelfItem()
{

}

QRectF MySelfItem::boundingRect() const{
	return  QRectF(0,0,10,10);
}

void MySelfItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	Q_UNUSED(option);  //标明该参数没有使用
	Q_UNUSED(widget);
	painter->setBrush(Qt::green);
	painter->drawRect(0, 0, 10, 10);

}