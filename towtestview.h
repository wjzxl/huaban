#ifndef TOWTESTVIEW_H
#define TOWTESTVIEW_H

#include <QObject>
#include <QWidget>
#include <QPointF>
#include <QGraphicsScene>
#include <QMap>
#include <QGraphicsSceneMouseEvent>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QList>

class ObjItem;
class LineToItem;
class rectboundItem;
class CircleItem;
class TexteditItem;

struct InkDData{
	QPointF prePoint;
	std::vector<QGraphicsItem*> TempDrawingItem;
	ObjItem* Element;
	InkDData(){
		this->Element = Q_NULLPTR;
		this->TempDrawingItem.clear();
	}
};

class TowTestView : public QGraphicsScene
{
	Q_OBJECT

public:
	TowTestView(QObject *parent=0);

	void setColor(const QColor& color){ this->_inkColor = color; }
	void setThickness(int w){ this->_inkThickness = w; }
	void onDeviceDown(const QPointF& pt, int id = 0);
	void onDeviceMove(const QPointF& pt, int id = 0);
	void onDeviceUp(int id = 0);
	int getThickness(){ return this->_inkThickness; }

	int Tagsecen;
	bool useEnable;
	int currentOpertor;
	int SorX;

public:
	LineToItem *linshiItem;
	QGraphicsItem *TempItem;
	QPointF SatrtPoint;

	rectboundItem *linshRectItem;
	CircleItem *linshicircleItem;

	TexteditItem *linshiTextitem;
	QGraphicsTextItem *TempItemTex;
	QPointF StartPoint;
	bool isEditText;
	bool isDragTopos;

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void drawStart(InkDData* dt);
	void drawTo(InkDData* dt, const QPointF& to);

signals:
	void changeThemouseStatue(QCursor);

private:
	QMap< int, InkDData* > _itemMap;
	QColor _inkColor;
	int _inkThickness;
	bool _isDrawing;
};
	

#endif // TOWTESTVIEW_H
