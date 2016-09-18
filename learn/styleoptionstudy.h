#ifndef STYLEOPTIONSTUDY_H
#define STYLEOPTIONSTUDY_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class StyleOptionStudy : public QPushButton
{
    Q_OBJECT
public:
    explicit StyleOptionStudy(QWidget *parent = 0);

signals:

public slots:

private slots:
    void paintEvent(QPaintEvent *);
};

#endif // STYLEOPTIONSTUDY_H
