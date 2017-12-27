#ifndef FIRSTTEST_H
#define FIRSTTEST_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>

#include "towtestview.h"

class FirstTest : public QGraphicsView
{
	Q_OBJECT

public:
	FirstTest(QWidget *parent = 0);
	~FirstTest();

	void setInkColor(const QColor* color);
	void setInkThickness(int thickness);
	TowTestView* currentSlide(void)const{ return this->_currentSlide; }
	void setScene(TowTestView *scene);

	void addOneSecens();

	int currentOpertor;

protected:
	void resizeEvent(QResizeEvent *event);

	virtual bool viewportEvent(QEvent *event);
public slots:
    void rectviceMouseChnage(QCursor cursor);



private:
	TowTestView* _currentSlide;
	bool _isTouchMode;
Q_SIGNALS:
	void slideChangedBefore(void);
	void slideChangedAfter(void);
};

#endif // FIRSTTEST_H
