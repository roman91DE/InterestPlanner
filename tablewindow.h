#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "financial_plan_backend.h"
#include <memory>
#include <QTableWidget>


class tableWindow : public QTableWidget
{
    Q_OBJECT
private:
    std::shared_ptr <financial_plan> finance_plan;

public:
    explicit tableWindow(std::shared_ptr <financial_plan> f, QWidget *parent = nullptr);
    ~tableWindow();

};

#endif // TABLEWINDOW_H
