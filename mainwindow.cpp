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
	TipWordLab->setText("简单画板的制作");
	TipWordLab->setGeometry(10, 20, this->size().width() - 20, 40);
	TipWordLab->setStyleSheet("font-size:30px;color:#FE7777;font-weight:regular;font-style:PingFang SC");
	TipWordLab->setAlignment(Qt::AlignCenter);

	//mylabshow *myLBa = new mylabshow(this);
	//myLBa->namtalbe->setText("jdjjdj都是分开计算的都是jfk撒圣诞节反抗拉萨");
	//myLBa->namtalbe->setGeometry(10, 40, this->size().width() - 20, 40);
	//myLBa->namtalbe->setStyleSheet("font-size:30px;color:#FE7777;font-weight:regular;font-style:PingFang SC");
	//myLBa->widget()->resize(60, 100);  // 手动调整大小


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
			RloadTheBut->setText("画笔");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(pathDrawCiclik()));
		}
		else if (i == 1){
			RloadTheBut->setText("实线");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_lineDrawCiclik()));
		}
		else if (i == 2){
			RloadTheBut->setText("虚线");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_lineDrawCiclik()));
		}
		else if (i == 3){
			RloadTheBut->setText("实线矩形");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_rectDrawCiclik()));
		}
		else if (i == 4){
			RloadTheBut->setText("虚线矩形");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_rectDrawCiclik()));
		}
		else if (i == 5){
			RloadTheBut->setText("实线圆");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_circleCiclik()));
		}
		else if (i == 6){
			RloadTheBut->setText("虚线圆");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_circleCiclik()));
		}
		else if (i == 7){
			RloadTheBut->setText("实线箭头");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(S_arrowCiclik()));
		}
		else if (i == 8){
			RloadTheBut->setText("虚线箭头");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(X_arrowCiclik()));
		}
		else if (i == 9){
			RloadTheBut->setText("文字编辑");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(textEditCiclik()));
		}
		else if (i == 10){
			RloadTheBut->setText("橡皮擦");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(earserCiclik()));
		}
		else if (i == 11){
			RloadTheBut->setText("还原");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(resueCiclik()));
		}
		else if (i == 12){
			RloadTheBut->setText("撤销");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(revokeCiclik()));
		}
		else if (i == 13){
			RloadTheBut->setText("清屏");
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
			RloadTheBut->setText("画笔的大小");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(changeThePanFontCiclik()));
		}
		else if (j == 1){
			RloadTheBut->setText("画笔的颜色");
			connect(RloadTheBut, SIGNAL(clicked()), this, SLOT(changeTheColorCiclik()));
		}
		else if (j == 2){
			RloadTheBut->setText("放大和缩小");
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

}//画笔
void MainWindow::S_lineDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSLine;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//实线
void MainWindow::X_lineDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXLine;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//虚线
void MainWindow::S_rectDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSRect;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;

}//矩形实线
void MainWindow::X_rectDrawCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXRect;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//矩形虚线
void MainWindow::S_circleCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSCircle;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//圆实线
void MainWindow::X_circleCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXCircle;


	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//圆虚线
void MainWindow::S_arrowCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeSArrow;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//箭头实线
void MainWindow::X_arrowCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeXArrow;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 1;
}//箭头虚线
void MainWindow::textEditCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeText;

	MainTestView->currentSlide()->setThickness(5);
	MainTestView->currentSlide()->setColor(Qt::black);
	MainTestView->currentSlide()->currentOpertor = opertorCurr;
	MainTestView->currentSlide()->SorX = 0;
}//文本编辑

void MainWindow::earserCiclik(){
	MainTestView->setEnabled(true);
	opertorCurr = DrawTypeEarser;


	MainTestView->currentSlide()->currentOpertor = opertorCurr;

}//橡皮擦
void MainWindow::resueCiclik(){
	MainTestView->setEnabled(true);
	
}//还原
void MainWindow::revokeCiclik(){
	MainTestView->setEnabled(true);

}//撤销
void MainWindow::clearSeccenCiclik(){
	MainTestView->setEnabled(true);
	
}//清除

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

	
}//画笔粗细选择
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

	
	
}//画笔颜色选择

void MainWindow::changTheSizeCiclik(){
}//绘制的item放大缩小切换

MainWindow::~MainWindow()
{
    delete ui;
}
