#include "tablewindow.h"
#include "ui_tablewindow.h"
#include <QTableWidget>

tableWindow::tableWindow(std::shared_ptr <financial_plan> f, QWidget *parent)
    : QTableWidget(parent), finance_plan(f)
{
    int cols = 5;
    int rows = this->finance_plan->get_totalTime()+1;
    this->setRowCount(rows);
    this->setColumnCount(cols);
    this->setGeometry(0,0,600,600);

    this->show();
}

tableWindow::~tableWindow() {
}
