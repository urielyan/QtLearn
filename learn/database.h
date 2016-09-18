#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QtSql>
#include <QTableView>
#include <QStackedLayout>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

class DataBase : public QDialog
{
    Q_OBJECT
public:
    DataBase();

    QSqlTableModel model() const;
    void setModel(const QSqlTableModel &model);

private:
    bool connectDataBase(QString driver, QString name);
    void initView();
    void initSqlTableModel();
    void initSqlRelationTableModel();
    void initLayout();

    QSqlDatabase m_sqlDatabase;
    QSqlQueryModel *p_SqlQueryModel;
    QSqlTableModel *p_SqlTableModel;
    QSqlRelationalTableModel *p_SqlRelationTableModel;
    QTableView *p_Tableview;

    QStackedLayout m_mainStackedLayout;
};

/***
 * test:
 *  CREATE TABLE employee(id int primary key not null, department);
 *      insert into  employee values(1, 'software');
 *  CREATE TABLE people(identificationint not null primary key, employee_id, name, age, address, sex, foreign key (employee_id) references employee(id));
 *      insert into  people values(000001,1, 'yange2', 23, 'songjiang', 23);
 */

#endif // DATABASE_H
