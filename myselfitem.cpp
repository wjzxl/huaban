#include "myselfitem.h"

MySelfItem::MySelfItem()
{
	//setFlag(ItemIsMovable);//�����ƶ�

}

MySelfItem::~MySelfItem()
{

}

QRectF MySelfItem::boundingRect() const{
	return  QRectF(0,0,10,10);
}

void MySelfItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	Q_UNUSED(option);  //�����ò���û��ʹ��
	Q_UNUSED(widget);
	painter->setBrush(Qt::green);
	painter->drawRect(0, 0, 10, 10);

}