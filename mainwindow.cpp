#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firsttest.h"
#include "mylabshow.h"

#include <QPushButton>
#include <QLabel>

# pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	setMinimumSize(1200,1000);
	setMaximumSize(1200,1000);

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);

	MainTestView = new FirstTest(this);
	MainTestView->setStyleSheet("background:#DAF4EE");
	MainTestView->setGeometry(200, 200, 800, 600);
	MainTestView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	MainTestView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	MainTestView->addOneSecens();
	MainTestView->setEnabled(false);
	//MainTestView->setMinimumSize(QSize(800, 600));
	//MainTestView->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

	QLabel *TipWordLab = new QLabel(this);
	TipWordLab->setAttribute(Qt::WA_TranslucentBackground);
	TipWordLab->setText("�򵥻��������");
	TipWordLab->setGeometry(10, 20, this->size().width() - 20, 40);
	TipWordLab->setStyleSheet("font-size:30px;color:#FE7777;font-weight:regular;font-style:PingFang SC");
	TipWordLab->setAlignment(Qt::AlignCenter);

	//mylabshow *myLBa = new mylabshow(this);
	//myLBa->namtalbe->setText("jdjjdj���Ƿֿ�����Ķ���jfk��ʥ���ڷ�������");
	//myLBa->namtalbe->setGeometry(10, 40, this->size().width() - 20, 40);
	//myLBa->namtalbe->setStyleSheet("font-size:30px;color:#FE7777;font-weight:regular;font-style:PingFang SC");
	//myLBa->widget()->resize(60, 100);  // �ֶ�������С


	opertorCurr = -1;
	UserColorCurr = Qt::black;
	UserFontCurr = 5;
	currentColor = 0;

	addButTochoose();

}

void MainWindow::addButTochoose(){
	ToolBarLab = new QLabel(this);
	//ToolBarLab->setAttribute(Qt::WA_TranslucentBackground);
	ToolBarLab->setGeometry(10, 200, 180, 600);
	ToolBarLab->setStyleSheet("background-color:#FFAD3F;border:2px;border-radius:10px;border-color:#4A90E2");
	//setStyleSheet("QPushButton{background-color:#fbc143;color:white;border-radius:2px;border:0px;}"
		//"QPushButton:hover{background-color:#DAA520;}");
	for (int i = 0; i < 14; i++){
		QPushButton *RloadTheBut = new QPushButton(ToolBarLab);
		
		RloadTheBut->setGeometry(QRect(30, 10+(30+5)*i, 120, 30));
		RloadTheBut->setStyleSheet("QPushButton{background-color:#FFFFFF;font-size:16px;font-weight:regular;color:#F713FE;border:1px;border-style:solid;border-color:#FCB314 #FCB314;border-radius:2px}" 
			"QPushButton:hover{background-color:#DAA520;}"
			);
		RloadTheBut->setDefault(false);
		if (i == 0){
			RloadTheBut->setText("����");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(pathDrawCiclik()));
		}
		else if (i == 1){
			RloadTheBut->setText("ʵ��");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_lineDrawCiclik()));
		}
		else if (i == 2){
			RloadTheBut->setText("����");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_lineDrawCiclik()));
		}
		else if (i == 3){
			RloadTheBut->setText("ʵ�߾���");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_rectDrawCiclik()));
		}
		else if (i == 4){
			RloadTheBut->setText("���߾���");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_rectDrawCiclik()));
		}
		else if (i == 5){
			RloadTheBut->setText("ʵ��Բ");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_circleCiclik()));
		}
		else if (i == 6){
			RloadTheBut->setText("����Բ");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_circleCiclik()));
		}
		else if (i == 7){
			RloadTheBut->setText("ʵ�߼�ͷ");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_arrowCiclik()));
		}
		else if (i == 8){
			RloadTheBut->setText("���߼�ͷ");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_arrowCiclik()));
		}
		else if (i == 9){
			RloadTheBut->setText("���ֱ༭");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(textEditCiclik()));
		}
		else if (i == 10){
			RloadTheBut->setText("��Ƥ��");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(earserCiclik()));
		}
		else if (i == 11){
			RloadTheBut->setText("��ԭ");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(resueCiclik()));
		}
		else if (i == 12){
			RloadTheBut->setText("����");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(revokeCiclik()));
		}
		else if (i == 13){
			RloadTheBut->setText("����");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(clearSeccenCiclik()));
		}
		
	}

	ToolChooseLab = new QLabel(this);
	ToolChooseLab->setGeometry(200, 850, 800, 60);
	ToolChooseLab->setStyleSheet("background-color:#FFAD3F;border:1px;border-radius:6px;border-color:#4A90E2");

	for (int j = 0; j < 3; j++){
		QPushButton *RloadTheBut = new QPushButton(ToolChooseLab);

		RloadTheBut->setGeometry(QRect(50+(150+20)*j, 15, 150, 30));
		RloadTheBut->setStyleSheet("QPushButton{background-color:#FFFFFF;font-size:16px;font-weight:regular;color:#F713FE;border:1px;border-style:solid;border-color:#FCB314 #FCB314;border-radius:2px}" 
			"QPushButton:hover{background-color:#DAA520;}");
		RloadTheBut->setDefault(false);
		if (j == 0){
			RloadTheBut->setText("���ʵĴ�С");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(changeThePanFontCiclik()));
		}
		else if (j == 1){
			RloadTheBut->setText("���ʵ���ɫ");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(changeTheColorCiclik()));
		}
		else if (j == 2){
			RloadTheBut->setText("�Ŵ����С");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(changTheSizeCiclik()));
		}
	}
}

void MainWindow::pathDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypePath;

	MainTestView->currentSlide()->setThickness(UserFontCurr);
	MainTestView->currentSlide()->setColor(UserColorCurr);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;

}//����
void MainWindow::S_lineDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSLine;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//ʵ��
void MainWindow::X_lineDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXLine;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//����
void MainWindow::S_rectDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSRect;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;

}//����ʵ��
void MainWindow::X_rectDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXRect;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//��������
void MainWindow::S_circleCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSCircle;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//Բʵ��
void MainWindow::X_circleCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXCircle;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//Բ����
void MainWindow::S_arrowCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSArrow;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//��ͷʵ��
void MainWindow::X_arrowCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXArrow;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//��ͷ����
void MainWindow::textEditCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeText;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//�ı��༭

void MainWindow::earserCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeEarser;


	MainTestView->currentSlide()->currentOpertor = opertorCurr;

}//��Ƥ��
void MainWindow::resueCiclik(){
	MainTestView->setEnabled(true);
	
}//��ԭ
void MainWindow::revokeCiclik(){
	MainTestView->setEnabled(true);

}//����
void MainWindow::clearSeccenCiclik(){
	MainTestView->setEnabled(true);
	
}//���

void MainWindow::changeThePanFontCiclik(){

	if (opertorCurr == DrawTypePath){
		if (UserFontCurr == 5){
			UserFontCurr = 10;
		}
		else if (UserFontCurr == 10)
		{
			UserFontCurr = 20;

		}
		else if (UserFontCurr == 20)
		{
			UserFontCurr = 5;
		}


		MainTestView->currentSlide()->setThickness(UserFontCurr);
	}

	
}//���ʴ�ϸѡ��
void MainWindow::changeTheColorCiclik(){

	if (opertorCurr == DrawTypePath){
		if (currentColor == 0){
			UserColorCurr = Qt::red;
		}
		else if (currentColor == 1)
		{
			UserColorCurr = Qt::blue;
		}
		else if (currentColor == 2)
		{
			UserColorCurr = Qt::cyan;
		}
		else if (currentColor == 3){
			UserColorCurr = Qt::magenta;
		}
		else if (currentColor == 4)
		{
			UserColorCurr = Qt::green;
		}
		else if (currentColor == 5)
		{
			UserColorCurr = Qt::black;
		}

		MainTestView->currentSlide()->setColor(UserColorCurr);

		if (currentColor == 5){
			currentColor = 0;
		}
		else
		{
			currentColor++;
		}
	}

	
	
}//������ɫѡ��

void MainWindow::changTheSizeCiclik(){
}//���Ƶ�item�Ŵ���С�л�

MainWindow::~MainWindow()
{
    delete ui;
}
