#include "towtestview.h"

#include <QCursor>
#include <QTextCodec>
#include <QTextDocument>
#include <QObject>
#include <QTextCursor>
#include "mainwindow.h"


#include "objitem.h"
#include "linetoitem.h"
#include "rectbounditem.h"
#include "circleitem.h"
#include "textedititem.h"

TowTestView::TowTestView(QObject *parent)
: QGraphicsScene(parent)
{
	this->_isDrawing = false;

	this->setBackgroundBrush(Qt::white);

	TempItem = NULL;
	linshiItem = NULL;
	linshRectItem = NULL;
	linshicircleItem = NULL;
	linshiTextitem = NULL;
	TempItemTex = NULL;

	isEditText = false;
	isDragTopos = false;
}

void TowTestView::drawStart(InkDData *dt){
	double x = dt->prePoint.x() - (double(_inkThickness) / 2.f);
	double y = dt->prePoint.y() - (double(_inkThickness) / 2.f);

	QGraphicsEllipseItem* el = addEllipse(QRect(x, y, _inkThickness, _inkThickness),
		QPen(_inkColor, 1), QBrush(_inkColor));

	dt->TempDrawingItem.push_back(el);
}

void TowTestView::drawTo(InkDData *dt, const QPointF &to){
	QGraphicsLineItem* li = addLine(dt->prePoint.x(),
		dt->prePoint.y(),
		to.x(), to.y(),
		QPen(QBrush(_inkColor), _inkThickness, Qt::SolidLine,
		Qt::RoundCap, Qt::RoundJoin));

	dt->TempDrawingItem.push_back(li);
}

void TowTestView::onDeviceDown(const QPointF &pt, int id){
	if (_itemMap.keys().contains(id))
	{
		InkDData* dt = _itemMap.value(id);
		if (dt->Element)
			QGraphicsScene::removeItem(dt->Element);
		if (dt->TempDrawingItem.size() >= 1){
			for (size_t i = 0; i < dt->TempDrawingItem.size(); i++)
			{
				QGraphicsScene::removeItem(dt->TempDrawingItem[i]);
			}
		}

		dt->TempDrawingItem.clear();
		delete dt;

		_itemMap.remove(id);

	}

	InkDData* dt = new InkDData;
	dt->prePoint = pt;//scene point;
	dt->Element = new ObjItem;
	dt->Element->addPoint(pt);
	_itemMap.insert(id, dt);

	this->drawStart(dt);

}

void TowTestView::onDeviceMove(const QPointF &pt, int id){
	if (_itemMap.keys().contains(id)){
		
		QPointF to = pt;

		if (to.x() > 1 && to.x() < this->width() && to.y()>1 && to.y() < this->height()){

			InkDData* dt = _itemMap.value(id);

			if (dt->Element)
				dt->Element->addPoint(to);

			this->drawTo(dt, to);
			dt->prePoint = to;
		}

		

	}
}

void TowTestView::onDeviceUp(int id){
	if (_itemMap.keys().contains(id)){
		InkDData* dt = _itemMap.value(id);
		for (size_t i = 0; i < dt->TempDrawingItem.size(); i++)
		{
			QGraphicsScene::removeItem(dt->TempDrawingItem[i]);
		}

		dt->TempDrawingItem.clear();
		dt->Element->setColor(_inkColor);
		dt->Element->setThickness(_inkThickness);
		dt->Element->render();
		QGraphicsScene::addItem(dt->Element);

		_itemMap.remove(id);
	}
}

#include <QGraphicsSceneMouseEvent>
void TowTestView::mousePressEvent(QGraphicsSceneMouseEvent *event){

	if (event->button() != Qt::LeftButton){
		event->ignore();  //如果不是鼠标左键按下，则忽略该事件
		return;
	}

	printf("\n**preesend****!!!!!!%f!!!!!!!!!!!!%f!!!!!!", event->scenePos().x(),event->scenePos().y());

	if (currentOpertor == DrawTypePath){
		this->_isDrawing = true;
		this->onDeviceDown(event->scenePos());
	}
	else if (currentOpertor == DrawTypeSLine || currentOpertor == DrawTypeXLine){
		this->_isDrawing = true;
		if (linshiItem)
			QGraphicsScene::removeItem((QGraphicsItem *)linshiItem);
		if (TempItem){
			QGraphicsScene::removeItem(TempItem);
		}
		linshiItem = NULL;
		TempItem = NULL;

		linshiItem = new LineToItem;
		linshiItem->SatrtPoint = event->scenePos();

		double x = linshiItem->SatrtPoint.x() - (double(_inkThickness) / 2.f);
		double y = linshiItem->SatrtPoint.y() - (double(_inkThickness) / 2.f);

		QGraphicsEllipseItem* el = addEllipse(QRect(x, y, _inkThickness, _inkThickness),
			QPen(_inkColor, 1), QBrush(_inkColor));

		TempItem = el;

	}
	else if (currentOpertor == DrawTypeSRect || currentOpertor == DrawTypeXRect){
		this->_isDrawing = true;
		if (linshRectItem)
			QGraphicsScene::removeItem((QGraphicsItem *)linshRectItem);
		if (TempItem){
			QGraphicsScene::removeItem(TempItem);
		}
		linshRectItem = NULL;
		TempItem = NULL;


		linshRectItem = new rectboundItem;
		linshRectItem->SatrtPoint = event->scenePos();

		double x = linshRectItem->SatrtPoint.x() - (double(_inkThickness) / 2.f);
		double y = linshRectItem->SatrtPoint.y() - (double(_inkThickness) / 2.f);

		QGraphicsEllipseItem* el = addEllipse(QRect(x, y, _inkThickness, _inkThickness),
			QPen(_inkColor, 1), QBrush(_inkColor));

		TempItem = el;
	}
	else if (currentOpertor == DrawTypeSCircle || currentOpertor == DrawTypeXCircle){
		this->_isDrawing = true;
		if (linshicircleItem)
			QGraphicsScene::removeItem((QGraphicsItem *)linshicircleItem);
		if (TempItem){
			QGraphicsScene::removeItem(TempItem);
		}
		linshicircleItem = NULL;
		TempItem = NULL;


		linshicircleItem = new CircleItem;
		linshicircleItem->SatrtPoint = event->scenePos();

		double x = linshicircleItem->SatrtPoint.x() - (double(_inkThickness) / 2.f);
		double y = linshicircleItem->SatrtPoint.y() - (double(_inkThickness) / 2.f);

		QGraphicsEllipseItem* el = addEllipse(QRect(x, y, _inkThickness, _inkThickness),
			QPen(_inkColor, 1), QBrush(_inkColor));

		TempItem = el;
	}
	else if (currentOpertor == DrawTypeText){
		this->_isDrawing = false;

		if (isEditText){
			QPointF cupoint = event->scenePos();
			QRectF rectfd = TempItemTex->boundingRect();
			if (cupoint.x() <= StartPoint.x() + 2 && cupoint.x() >= StartPoint.x() - 5 && cupoint.y() <= StartPoint.y() + rectfd.height() && cupoint.y() >= StartPoint.y()){
				printf("可以进行移动了");
				isDragTopos = true;
			}
			else if (cupoint.x() < StartPoint.x() || cupoint.x() > StartPoint.x() + rectfd.width() || cupoint.y() > StartPoint.y() + rectfd.height() || cupoint.y() < StartPoint.y())
			{
				isDragTopos = false;
				if (linshiTextitem){
					//QGraphicsScene::removeItem((QGraphicsItem *)linshiTextitem);
					if (TempItemTex->toPlainText().length() > 0){
						linshiTextitem->setColor(_inkColor);
						linshiTextitem->setThickness(_inkThickness);
						linshiTextitem->SorX = 0;
						linshiTextitem->poiboundRect = TempItemTex->boundingRect();
						linshiTextitem->WidthS = TempItemTex->textWidth();
						linshiTextitem->contentStr = TempItemTex->toPlainText();
						linshiTextitem->render();
						QGraphicsScene::addItem(linshiTextitem);
					}

				}
				if (TempItemTex){
					QGraphicsScene::removeItem(TempItemTex);
				}

				linshiTextitem = NULL;
				TempItemTex = NULL;
				isEditText = false;
			}
			else
			{

			}
		}
		else
		{
			if (TempItemTex){
				QGraphicsScene::removeItem(TempItemTex);
			}

			linshiTextitem = NULL;
			TempItemTex = NULL;


			linshiTextitem = new TexteditItem;
			linshiTextitem->SatrtPoint = event->scenePos();
			StartPoint = event->scenePos();

			QGraphicsTextItem *el = new QGraphicsTextItem();//addText("", QFont("宋体", _inkThickness,QFont::Normal));
			el->setFont(QFont("宋体", _inkThickness, QFont::Normal));
			el->setDefaultTextColor(_inkColor);
			//el->setTextWidth(100);
			el->setPlainText("");
			el->setPos(linshiTextitem->SatrtPoint);
			el->setTextInteractionFlags(Qt::TextEditorInteraction);
			el->setFocus();
			QGraphicsScene::addItem(el);
			connect(el->document(), &QTextDocument::contentsChanged, [=]() {
				printf("%s  == %f   == %f\n", el->toPlainText().toLocal8Bit(), el->boundingRect().width(), el->boundingRect().height());
				if (el->boundingRect().width() + linshiTextitem->SatrtPoint.x() > this->width() - 5){
					el->setTextWidth(this->width() - 5 - linshiTextitem->SatrtPoint.x());
				}

				if (el->boundingRect().height() + linshiTextitem->SatrtPoint.y() > this->height() - 5){
					el->boundingRect().setHeight(this->height() - 5 - linshiTextitem->SatrtPoint.y());
				}

			});

			TempItemTex = el;

			isEditText = true;
		}
	}
}
void TowTestView::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

	if (currentOpertor == DrawTypePath){
		if (this->_isDrawing){
			this->onDeviceMove(event->scenePos());
		}
	}
	else if (currentOpertor == DrawTypeSLine || currentOpertor == DrawTypeXLine){
		if (this->_isDrawing){
			if (event->scenePos().x() > 1 && event->scenePos().x() < this->width() && event->scenePos().y()>1 && event->scenePos().y() < this->height()){

				if (TempItem){
					QGraphicsScene::removeItem(TempItem);
				}
				TempItem = NULL;
				QGraphicsLineItem* li = addLine(linshiItem->SatrtPoint.x(),
					linshiItem->SatrtPoint.y(),
					event->scenePos().x(), event->scenePos().y(),
					QPen(QBrush(_inkColor), _inkThickness, SorX == 0 ? Qt::SolidLine : Qt::DashLine,
					Qt::RoundCap, Qt::RoundJoin));
				TempItem = li;
			}
			else
			{
				return;
			}
		}
	}
	else if (currentOpertor == DrawTypeSRect || currentOpertor == DrawTypeXRect){
		if (this->_isDrawing){

			if (event->scenePos().x() > 1 && event->scenePos().x() < this->width() && event->scenePos().y()>1 && event->scenePos().y() < this->height()){
				if (TempItem){
					QGraphicsScene::removeItem(TempItem);
				}
				TempItem = NULL;

				QPointF stagdf = linshRectItem->SatrtPoint;
				if ((event->scenePos().x() - linshRectItem->SatrtPoint.x()) < 0 && (event->scenePos().y() - linshRectItem->SatrtPoint.y()) < 0){
					stagdf.setX(event->scenePos().x());
					stagdf.setY(event->scenePos().y());
				}
				else if ((event->scenePos().x() - linshRectItem->SatrtPoint.x()) < 0 && (event->scenePos().y() - linshRectItem->SatrtPoint.y()) >= 0){
					stagdf.setX(event->scenePos().x());
				}
				else if ((event->scenePos().x() - linshRectItem->SatrtPoint.x()) >= 0 && (event->scenePos().y() - linshRectItem->SatrtPoint.y()) < 0){
					stagdf.setY(event->scenePos().y());
				}

				QGraphicsRectItem * li = addRect(stagdf.x(),
					stagdf.y(),
					fabs(event->scenePos().x() - linshRectItem->SatrtPoint.x()), fabs(event->scenePos().y() - linshRectItem->SatrtPoint.y()),
					QPen(QBrush(_inkColor), _inkThickness, SorX == 0 ? Qt::SolidLine : Qt::DashLine,
					Qt::RoundCap, Qt::RoundJoin));

				/*QRectF linshiRectF = QRectF(linshRectItem->SatrtPoint,event->scenePos());

				if ((event->scenePos().x() - linshRectItem->SatrtPoint.x()) < 0 || (event->scenePos().y() - linshRectItem->SatrtPoint.y()) < 0){
				linshiRectF = QRectF(event->scenePos(), linshRectItem->SatrtPoint);
				}

				QGraphicsRectItem * li = addRect(linshiRectF,
				QPen(QBrush(_inkColor), _inkThickness, SorX == 0 ? Qt::SolidLine : Qt::DashLine,
				Qt::RoundCap, Qt::RoundJoin));*/
				TempItem = li;
			}
			else
			{
				return;
			}
		}
	}
	else if (currentOpertor == DrawTypeSCircle || currentOpertor == DrawTypeXCircle){
		if (this->_isDrawing){

			if (event->scenePos().x() > 1 && event->scenePos().x() < this->width() && event->scenePos().y()>1 && event->scenePos().y() < this->height()){

				if (TempItem){
					QGraphicsScene::removeItem(TempItem);
				}
				TempItem = NULL;

				QPointF enshdd = event->scenePos();

				int widhfh = fabs(enshdd.x() - linshicircleItem->SatrtPoint.x());
				int heightdd = fabs(enshdd.y() - linshicircleItem->SatrtPoint.y());


				if (linshicircleItem->SatrtPoint.x() + double(widhfh) / 2.f > this->width()-5){
					widhfh = (this->width() - 5 - linshicircleItem->SatrtPoint.x()) * 2;
				}

				if (linshicircleItem->SatrtPoint.x() - double(widhfh) / 2.f < 0){
					widhfh = linshicircleItem->SatrtPoint.x();
				}

				if (linshicircleItem->SatrtPoint.y() + double(heightdd) / 2.f > this->height() - 5){
					heightdd = (this->height() - 5 - linshicircleItem->SatrtPoint.y()) * 2;
				}

				if (linshicircleItem->SatrtPoint.y() - double(heightdd) / 2.f < 0){
					heightdd = linshicircleItem->SatrtPoint.y();
				}

				double x = linshicircleItem->SatrtPoint.x() - (double(widhfh) / 2.f);
				double y = linshicircleItem->SatrtPoint.y() - (double(heightdd) / 2.f);


				QGraphicsEllipseItem* li = addEllipse(QRect(x, y, widhfh, heightdd),
					QPen(QBrush(_inkColor), _inkThickness, SorX == 0 ? Qt::SolidLine : Qt::DashLine,
					Qt::RoundCap, Qt::RoundJoin), QBrush());

				TempItem = li;
			}
			else
			{
				return;
			}   
		}
	}
	else if (currentOpertor == DrawTypeText)
	{
		if (isEditText && !this->_isDrawing && !isDragTopos){
			printf("sdjkhfjdshfjasfhsjka\n");
			QPointF cupoint = event->scenePos();
			QRectF rectfd = TempItemTex->boundingRect();
			if (cupoint.x() <= StartPoint.x() + 2 && cupoint.x() >= StartPoint.x() - 5 && cupoint.y() <= StartPoint.y() + rectfd.height() && cupoint.y() >= StartPoint.y()){
				//isDragTopos = true;
				emit changeThemouseStatue(Qt::SizeAllCursor);
			}
			else{
				//isDragTopos = false;
				emit changeThemouseStatue(Qt::ArrowCursor);
			}
		}
		else if (isEditText && !this->_isDrawing && isDragTopos)
		{

			TempItemTex->setPos(event->scenePos());
		}
		
	}
}

void TowTestView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
	if (currentOpertor == DrawTypePath){
		if (this->_isDrawing){
			this->_isDrawing = false;
			this->onDeviceUp();
		}
	}
	else if (currentOpertor == DrawTypeSLine || currentOpertor == DrawTypeXLine){

		if (this->_isDrawing){
			this->_isDrawing = false;

			QPointF ebndldld = event->scenePos();

			if (event->scenePos().x() < 0){
				ebndldld.setX(1);
			}

			if (event->scenePos().x() > this->width()){
				ebndldld.setX(this->width());
			}

			if (event->scenePos().y() < 0){
				ebndldld.setY(1);
			}
			
			if (event->scenePos().y() > this->height()){
				ebndldld.setY(this->height());
			}


			if (TempItem){
				QGraphicsScene::removeItem(TempItem);
			}

			TempItem = NULL;

			linshiItem->setColor(_inkColor);
			linshiItem->setThickness(_inkThickness);
			linshiItem->ensdPoint = ebndldld;
			linshiItem->SorX = SorX;
			linshiItem->render();
			QGraphicsScene::addItem(linshiItem);

			linshiItem = NULL;
		}
	}
	else if (currentOpertor == DrawTypeSRect || currentOpertor == DrawTypeXRect){

		if (this->_isDrawing){
			this->_isDrawing = false;
			if (TempItem){
				QGraphicsScene::removeItem(TempItem);
			}

			TempItem = NULL;

			QPointF ebndldld = event->scenePos();

			if (event->scenePos().x() < 0){
				ebndldld.setX(1);
			}

			if (event->scenePos().x() > this->width()-5){
				ebndldld.setX(this->width()-5);
			}

			if (event->scenePos().y() < 0){
				ebndldld.setY(1);
			}

			if (event->scenePos().y() > this->height()-5){
				ebndldld.setY(this->height()-5);
			}

			if ((linshRectItem->SatrtPoint.x() - ebndldld.x() >= 0) && (linshRectItem->SatrtPoint.y() - ebndldld.y() >= 0)){
				
				QPointF stagd;
				stagd.setX(linshRectItem->SatrtPoint.x());
				stagd.setY(linshRectItem->SatrtPoint.y());
				linshRectItem->ensdPoint = stagd;
				linshRectItem->SatrtPoint = ebndldld;
			}
			else if ((linshRectItem->SatrtPoint.x() - event->scenePos().x() >= 0) && (linshRectItem->SatrtPoint.y() - event->scenePos().y() <= 0)){
				QPointF stagd;
				stagd.setX(linshRectItem->SatrtPoint.x());
				stagd.setY(ebndldld.y());
				linshRectItem->ensdPoint = stagd;


				QPointF stagd1;
				stagd1.setX(ebndldld.x());
				stagd1.setY(linshRectItem->SatrtPoint.y());
				linshRectItem->SatrtPoint = stagd1;
			}
			else if ((linshRectItem->SatrtPoint.x() - ebndldld.x() <= 0) && (linshRectItem->SatrtPoint.y() - ebndldld.y() >= 0)){
				QPointF stagd;
				stagd.setX(ebndldld.x());
				stagd.setY(linshRectItem->SatrtPoint.y());
				linshRectItem->ensdPoint = stagd;


				QPointF stagd1;
				stagd1.setX(linshRectItem->SatrtPoint.x());
				stagd1.setY(ebndldld.y());
				linshRectItem->SatrtPoint = stagd1;
			}
			else
			{
				linshRectItem->ensdPoint = ebndldld;
			}

			linshRectItem->setColor(_inkColor);
			linshRectItem->setThickness(_inkThickness);
			linshRectItem->SorX = SorX;
			linshRectItem->render();
			QGraphicsScene::addItem(linshRectItem);

			linshRectItem = NULL;
		}
	}
	else if (currentOpertor == DrawTypeSCircle || currentOpertor == DrawTypeXCircle){

		if (this->_isDrawing){
			this->_isDrawing = false;
			if (TempItem){
				QGraphicsScene::removeItem(TempItem);
			}

			TempItem = NULL;

			QPointF ebndldld = event->scenePos();

			int widhfh = fabs(ebndldld.x() - linshicircleItem->SatrtPoint.x());
			int heightdd = fabs(ebndldld.y() - linshicircleItem->SatrtPoint.y());

			if (linshicircleItem->SatrtPoint.x() + double(widhfh) / 2.f > this->width() - 5){
				widhfh = (this->width() - 5 - linshicircleItem->SatrtPoint.x()) * 2;
				ebndldld.setX(linshicircleItem->SatrtPoint.x()+widhfh);
			}

			if (linshicircleItem->SatrtPoint.x() - double(widhfh) / 2.f < 0){
				widhfh = linshicircleItem->SatrtPoint.x();
				ebndldld.setX(linshicircleItem->SatrtPoint.x() - widhfh);
			}

			if (linshicircleItem->SatrtPoint.y() + double(heightdd) / 2.f > this->height() - 5){
				heightdd = (this->height() - 5 - linshicircleItem->SatrtPoint.y()) * 2;
				ebndldld.setY(linshicircleItem->SatrtPoint.y() - heightdd);
			}

			if (linshicircleItem->SatrtPoint.y() - double(heightdd) / 2.f < 0){
				heightdd = linshicircleItem->SatrtPoint.y();
				ebndldld.setY(linshicircleItem->SatrtPoint.y()-heightdd);
			}

			linshicircleItem->setColor(_inkColor);
			linshicircleItem->setThickness(_inkThickness);
			linshicircleItem->ensdPoint = ebndldld;
			linshicircleItem->SorX = SorX;
			linshicircleItem->render();
			QGraphicsScene::addItem(linshicircleItem);

			linshicircleItem = NULL;
		}
	}
	else if (currentOpertor == DrawTypeText)
	{
		if (isEditText && !this->_isDrawing &&isDragTopos){
			printf("移动结束\n");
			isDragTopos = false;
			linshiTextitem->SatrtPoint = event->scenePos();
			StartPoint = event->scenePos();
		}

	}
}
