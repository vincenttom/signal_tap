#include "signaltap.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignalTap w;
    w.show();

    return a.exec();
}
