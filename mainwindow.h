#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QList>
#include <QLabel>

namespace Ui {
class MainWindow;
}


enum OperTheType{
	DrawTypePath = 0,
	DrawTypeSLine,
	DrawTypeXLine,
	DrawTypeSRect,
	DrawTypeXRect,
	DrawTypeSCircle,
	DrawTypeXCircle,
	DrawTypeSArrow,
	DrawTypeXArrow,
	DrawTypeText,
	DrawTypeEarser
};

class FirstTest;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


	void addButTochoose();

	int opertorCurr;
	int currentColor;
	QColor UserColorCurr;
	int UserFontCurr;

	QLabel *ToolBarLab;
	QLabel *ToolChooseLab;

	FirstTest *MainTestView;

public slots:
    void pathDrawCiclik();//画笔
	void S_lineDrawCiclik();//实线
	void X_lineDrawCiclik();//虚线
	void S_rectDrawCiclik();//矩形实线
	void X_rectDrawCiclik();//矩形虚线
	void S_circleCiclik();//圆实线
	void X_circleCiclik();//圆虚线
	void S_arrowCiclik();//箭头实线
	void X_arrowCiclik();//箭头虚线
	void textEditCiclik();//文本编辑

	void earserCiclik();//橡皮擦
	void resueCiclik();//还原
	void revokeCiclik();//撤销
	void clearSeccenCiclik();//清除

	void changeThePanFontCiclik();//画笔粗细选择
	void changeTheColorCiclik();//画笔颜色选择

	void changTheSizeCiclik();//绘制的item放大缩小切换

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
