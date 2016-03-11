#include <QApplication>

#include "draw_widget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    draw_widget d;
 	d.show();
    return app.exec();
}
