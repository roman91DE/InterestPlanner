#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "financial_plan_backend.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // tool tips
    ui->constant_annuity_button->setToolTip("Kredittilgung mit konstanter Annuitätszahlung");
    ui->constant_interest_button->setToolTip("Endfällige Kredittilgung mit konstanter Zinszahlung");
    ui->constant_repay_button->setToolTip("Kredittilgung mit konstanter Tilgungszahlung");

    // connecting push buttons
    connect(ui->constant_repay_button, SIGNAL(clicked()), this, SLOT(slot_clicked_const_repay()));
    connect(ui->constant_interest_button, SIGNAL(clicked()), this, SLOT(slot_clicked_const_interest()));
    connect(ui->constant_annuity_button, SIGNAL(clicked()), this, SLOT(slot_clicked_const_annuity()));
}

// methods
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::generateTableWindow(std::shared_ptr <financial_plan> f) {
        // f enthält financial plan obj (1 der 3 subklassen)
        // konstruktor für neues fenster in dem sich tabelle aufbaut hier aufrufen
}


// slots
void MainWindow::slot_clicked_const_repay() {
    double capital = ui->input_capital->value();
    double interest = ui->input_interestrate->value();
    int time = ui->input_time_int->value();
    std::shared_ptr <financial_plan> f = std::make_shared<constant_repayment>(capital, interest,time);
    generateTableWindow(f);
}

void MainWindow::slot_clicked_const_interest() {
    double capital = ui->input_capital->value();
    double interest = ui->input_interestrate->value();
    int time = ui->input_time_int->value();
    std::shared_ptr <financial_plan> f = std::make_shared<constant_interest>(capital, interest,time);
    generateTableWindow(f);
}

void MainWindow::slot_clicked_const_annuity() {
    double capital = ui->input_capital->value();
    double interest = ui->input_interestrate->value();
    int time = ui->input_time_int->value();
    std::shared_ptr <financial_plan> f = std::make_shared<constant_annuity>(capital, interest,time);
    generateTableWindow(f);
}

