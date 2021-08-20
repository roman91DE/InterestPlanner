#include "tablewindow.h"
#include <QTableWidget>

tableWindow::tableWindow(std::shared_ptr<financial_plan> f, QWidget *parent)
    : QTableWidget(parent), finance_plan(f) {
  int cols = 5;

  int rows = this->finance_plan->get_totalTime();
  this->setRowCount(rows);
  this->setColumnCount(cols);
  this->setGeometry(0, 0, 3000, 2000);
  const QStringList header_horizontal = {"Periode", "Tilgung", "Zinszahlungen",
                                         "Annuität", "Restliche Schuld"};
  this->setHorizontalHeaderLabels(header_horizontal);
  std::vector<std::vector<double>> data = finance_plan->get_matrix();
  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < cols; k++) {
      QTableWidgetItem *temp =
          new QTableWidgetItem(QString::number(data[i][k]));
      temp->setTextAlignment(Qt::AlignCenter);
      this->setItem(i, k, temp);
    }
  }
  this->showFullScreen();
}

tableWindow::~tableWindow() {}
