#include "WaveView.h"
#include "signaltap.h"
#include <errno.h>
#include "WaveTimeLine.h"
#include <QGraphicsItem>
#include "GraphicsView.h"

WaveView::WaveView(GraphicsView *parent):
    QGraphicsScene(parent)
{
    qDebug("parent(%d, %d)\n", parent->width(), parent->height());
    mGraphicsView = parent;

    mGraphicsView->setScene(this);

    mTimeLine = new WaveTimeLine();

    setBackgroundBrush(Qt::black);

    setPenStyle(Wave, Qt::green, Qt::SolidLine, 1);

    setPenStyle(Move, Qt::magenta, Qt::DashLine, 1);

}

void WaveView::setPenStyle(WaveView::Pen pen, QColor color, Qt::PenStyle style, qreal width)
{
    QPen *qpen;

    if (pen < 0 || pen >= MAX)
        throw -EINVAL;

    qpen = &mPens[pen];

    qpen->setColor(color);
    qpen->setStyle(style);
    qpen->setWidthF(width);
}

QGraphicsLineItem *WaveView::addLine(Pen pen, qreal x1, qreal y1, qreal x2, qreal y2)
{
    return QGraphicsScene::addLine(x1, y1, x2, y2, mPens[pen]);
}

void WaveView::drawPosedge(qreal x, qreal y, qreal height, qreal width, qreal count)
{
    qreal x1, y1;
    qreal x2, y2;
    qreal xx, yy;

    x1 = x;
    y1 = y;
    x2 = x;
    y2 = y - height;

    addLine(Wave, x, y, x, y2); // draw posedge
    addLine(Wave, x, y2, x + width, y2);

    yy = y - height;

    for (int i = 0; i < count; i++) {
        x2 = x + width * i;
        xx = x2 + width;

        addLine(Wave, x2, yy, xx, yy);
    }

}

void WaveView::drawNegedge(qreal x, qreal y, qreal height, qreal width, qreal count)
{
    qreal x1, y1;
    qreal x2, y2;
    qreal xx, yy;

    x1 = x;
    y1 = y;
    x2 = x;
    y2 = y + height;

    addLine(Wave, x, y, x, y2); // draw posedge
    addLine(Wave, x, y2, x + width, y2);

    yy = y + height;

    for (int i = 0; i < count; i++) {
        x2 = x + width * i;
        xx = x2 + width;

        addLine(Wave, x2, yy, xx, yy);
    }

}
void WaveView::drawTest()
{
    qreal height = 50;
    qreal width = 20;
    qreal x, y;

    x = 0;
    y = 100;

    for (int i = 0; i < 1000; i += 2) {
        drawPosedge(x + width * i, y, height, width, 1);
        drawNegedge(x + width * (i + 1), y - height, height, width, 1);
    }


    mTimeLine->setPen(mPens[Move]);
    mTimeLine->setLine(100, 0, 100, this->width());

    addItem(mTimeLine);

    QPointF point = mTimeLine->mapToScene(QPointF(100, 0));
    //QPointF point = mTimeLine->mapTo(QPointF(100, 0));

    qDebug("Point(%f, %f)\n",point.x(), point.y());
    qDebug("%f, %f\n",this->width(), this->height());
    qDebug("View(%d, %d)\n", mGraphicsView->width(), mGraphicsView->height());
}


