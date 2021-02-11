#ifndef TABWINDOW_H
#define TABWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class tabWindow : public QMainWindow{
Q_OBJECT
private:

public:
    tabWindow();
};

#endif // TABWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class financial_plan;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT
    // member
    private:
        Ui::MainWindow *ui;

    // methods
    private:
        void generateTableWindow(std::shared_ptr <financial_plan> f);
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();



    // slots
    public slots:
        void slot_clicked_const_repay();
        void slot_clicked_const_interest();
        void slot_clicked_const_annuity();
};
#endif // MAINWINDOW_H
