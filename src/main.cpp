#include <QApplication>
#include "chexwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon(":/chex-icon.svg"));
    EadWindow window;
    window.show();
    return QApplication::exec();
}
