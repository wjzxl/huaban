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
    void pathDrawCiclik();//����
	void S_lineDrawCiclik();//ʵ��
	void X_lineDrawCiclik();//����
	void S_rectDrawCiclik();//����ʵ��
	void X_rectDrawCiclik();//��������
	void S_circleCiclik();//Բʵ��
	void X_circleCiclik();//Բ����
	void S_arrowCiclik();//��ͷʵ��
	void X_arrowCiclik();//��ͷ����
	void textEditCiclik();//�ı��༭

	void earserCiclik();//��Ƥ��
	void resueCiclik();//��ԭ
	void revokeCiclik();//����
	void clearSeccenCiclik();//���

	void changeThePanFontCiclik();//���ʴ�ϸѡ��
	void changeTheColorCiclik();//������ɫѡ��

	void changTheSizeCiclik();//���Ƶ�item�Ŵ���С�л�

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
