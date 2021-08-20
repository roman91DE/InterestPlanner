#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include "financial_plan_backend.h"
#include <QMainWindow>
#include <QObject>
#include <QTableWidget>
#include <QWidget>
#include <memory>

class tableWindow : public QTableWidget {
  Q_OBJECT
private:
  std::shared_ptr<financial_plan> finance_plan;

public:
  explicit tableWindow(std::shared_ptr<financial_plan> f,
                       QWidget *parent = nullptr);
  ~tableWindow();
};

#endif // TABLEWINDOW_H
