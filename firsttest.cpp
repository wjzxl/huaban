#include "firsttest.h"

#include <QTouchEvent>
#include <QEvent>
#include <QWidget>
#include "objitem.h"
#include "towtestview.h"

# pragma execution_character_set("utf-8")

FirstTest::FirstTest(QWidget *parent)
	: QGraphicsView(parent)
{
	this->setInteractive(true);
	this->setOptimizationFlag(QGraphicsView::IndirectPainting);
	this->setCacheMode(QGraphicsView::CacheBackground);

	//for touch
	this->setAttribute(Qt::WA_AcceptTouchEvents);
	this->viewport()->setAttribute(Qt::WA_AcceptTouchEvents);

	setRenderHint(QPainter::Antialiasing, true);

	this->resize(800, 600);
}

void FirstTest::rectviceMouseChnage(QCursor cursor){
	this->setCursor(cursor);
}

void FirstTest::addOneSecens(){
	TowTestView *secen = new TowTestView();

	secen->setColor(Qt::black);
	secen->setThickness(5);

	this->setScene(secen);
	this->setSceneRect(0, 0, this->size().width(), this->size().height());
	this->resize(this->size().width(), this->size().height());

	secen->setSceneRect(0, 0, this->size().width(), this->size().height());

	connect(secen, SIGNAL(changeThemouseStatue(QCursor)), this, SLOT(rectviceMouseChnage(QCursor)));

}

FirstTest::~FirstTest()
{

}

void FirstTest::resizeEvent(QResizeEvent *event){
	Q_UNUSED(event);
	this->setSceneRect(0, 0, this->width(), this->height());
	this->centerOn(this->width() / 2, this->height() / 2);
}

void FirstTest::setScene(TowTestView *scene){
	Q_EMIT slideChangedBefore();
	QGraphicsView::setScene(scene);
	this->_currentSlide = scene;

	Q_EMIT slideChangedAfter();
}

bool FirstTest::viewportEvent(QEvent *event){
	// 处理touch事件
	// printf("\n******!!!!!!!!!!!!!!!!!!!!!!!!");
	QEvent::Type evType = event->type();
	if (evType == QEvent::TouchBegin || evType == QEvent::TouchUpdate || evType == QEvent::TouchEnd)
	{
		QTouchEvent* touchEvent = static_cast<QTouchEvent*>(event);
		QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints();

		foreach(const QTouchEvent::TouchPoint tp, touchPoints){
			//不考虑pad
			QPoint touchPos = QPoint(tp.pos().x(), tp.pos().y());
			if (tp.id() == 0){
				if (tp.state() == Qt::TouchPointPressed)
					this->_isTouchMode = true;
				else
					this->_isTouchMode = false;
			}

			QPointF scenepos = this->mapToScene(touchPos.x(), touchPos.y());
			switch (tp.state()){
			case Qt::TouchPointPressed:
				this->_currentSlide->onDeviceDown(scenepos, tp.id());
				break;
			case Qt::TouchPointMoved:
				this->_currentSlide->onDeviceMove(scenepos, tp.id());
				break;
			case Qt::TouchPointReleased:
				this->_currentSlide->onDeviceUp(tp.id());
				break;
			}

		}

		if (evType == QEvent::TouchEnd){
			// to do
		}

		return true;
	}

	return QGraphicsView::viewportEvent(event);
}
