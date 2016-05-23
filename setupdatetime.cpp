#include "setupdatetime.h"
#include "ui_setupdatetime.h"
#include "global.h"

#include <QMessageBox>

setupdatetime::setupdatetime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setupdatetime)
{
    ui->setupUi(this);
    this->setFont(QFont(FONT_NAME, FONT_SIZE ,QFont::Normal));
    ui->dateTimeEdit->setFont(QFont(FONT_NAME, FONT_SIZE*2 ,QFont::Normal));
    ui->dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
}

setupdatetime::~setupdatetime()
{
    delete ui;
}

void setupdatetime::on_pushButton_clicked()
{
    //return button
    ui->dateTimeEdit->setFocus();
    this->close();
}

void setupdatetime::on_pushButton_2_clicked()
{
    //ok button
    QMessageBox box;
    box.setFont(QFont(FONT_NAME, FONT_SIZE ,QFont::Normal));
    box.setText("需要保存此次修改的日期和时间么？");
    box.setStandardButtons(QMessageBox::Cancel|QMessageBox::Yes);
    int res = box.exec();
    if(res == QMessageBox::Yes){
        QString tmpstr("date -s ");
        tmpstr += " \"";
        tmpstr.append(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss"));
        tmpstr += "\"";
        int a = system(tmpstr.toLocal8Bit());
        int b = system("hwclock --systohc");
        QMessageBox msgbox;
        msgbox.setFont(QFont(FONT_NAME, FONT_SIZE ,QFont::Normal));
        if(a== -1 || b == -1){
            msgbox.setText("设置时间不成功");
            msgbox.exec();
        }else{
            msgbox.setText("设置时间成功!");
            msgbox.exec();
        }
        this->close();
    }
}

void setupdatetime::show_and_refresh(){
  ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
  ui->dateTimeEdit->setFocus();
  this->showFullScreen();
}

void setupdatetime::on_p_buttonPlus_clicked()
{
    switch (ui->dateTimeEdit->currentSection()) {
    case QDateTimeEdit::NoSection:
        break;
    case QDateTimeEdit::SecondSection:
        ui->dateTimeEdit->setTime(ui->dateTimeEdit->time().addSecs(5));
        break;
    case QDateTimeEdit::MinuteSection:
        ui->dateTimeEdit->setTime(ui->dateTimeEdit->time().addSecs(60));
        break;
    case QDateTimeEdit::HourSection:
        ui->dateTimeEdit->setTime(ui->dateTimeEdit->time().addSecs(3600));
        break;
    case QDateTimeEdit::DaySection:
        ui->dateTimeEdit->setDate(ui->dateTimeEdit->date().addDays(1));
        break;
    case QDateTimeEdit::MonthSection:
        ui->dateTimeEdit->setDate(ui->dateTimeEdit->date().addMonths(1));
        break;
    case QDateTimeEdit::YearSection:
        ui->dateTimeEdit->setDate(ui->dateTimeEdit->date().addYears(1));
        break;
    default:
        break;
    }

}

void setupdatetime::on_p_buttonSub_clicked()
{
    {
        switch (ui->dateTimeEdit->currentSection()) {
        case QDateTimeEdit::NoSection:
            break;
        case QDateTimeEdit::SecondSection:
            ui->dateTimeEdit->setTime(ui->dateTimeEdit->time().addSecs(-5));
            break;
        case QDateTimeEdit::MinuteSection:
            ui->dateTimeEdit->setTime(ui->dateTimeEdit->time().addSecs(-60));
            break;
        case QDateTimeEdit::HourSection:
            ui->dateTimeEdit->setTime(ui->dateTimeEdit->time().addSecs(-3600));
            break;
        case QDateTimeEdit::DaySection:
            ui->dateTimeEdit->setDate(ui->dateTimeEdit->date().addDays(-1));
            break;
        case QDateTimeEdit::MonthSection:
            ui->dateTimeEdit->setDate(ui->dateTimeEdit->date().addMonths(-1));
            break;
        case QDateTimeEdit::YearSection:
            ui->dateTimeEdit->setDate(ui->dateTimeEdit->date().addYears(-1));
            break;
        default:
            break;
        }

    }
}
