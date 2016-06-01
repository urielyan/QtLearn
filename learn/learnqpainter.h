#ifndef LEARNQPAINTER_H
#define LEARNQPAINTER_H

#include <QWidget>

class LearnQPainter : public QWidget
{
    Q_OBJECT
public:
    explicit LearnQPainter(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);

signals:

public slots:
};

#endif // LEARNQPAINTER_H
