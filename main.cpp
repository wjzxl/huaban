#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <Windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef _DEBUG
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);
	freopen("CONIN$", "r+t", stdin);
#endif

    MainWindow w;
    w.show();

    return a.exec();
}
