#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <QtDebug>
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Mana forma");
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool verifyName(QString name)
{
    QRegularExpression rx("[a-zA-Z]+");
    QRegularExpressionValidator v(rx, 0);

    int pos = 0;
    if(v.validate(name, pos) == QValidator::Acceptable)
        return true;
    else
        return false;
}


bool verifyEmail(QString email)
{
    QRegularExpression rx("^[^@\\s]+@[^@\\s\\.]+\\.[^@\\.\\s]+$");
    QRegularExpressionValidator v(rx, 0);

    int pos = 0;
    if(v.validate(email, pos) == QValidator::Acceptable)
        return true;
    else
        return false;

    return true;
}


bool verifyPhone(QString phone)
{
    QRegularExpression rx("^2[0-9]{7}");
    QRegularExpressionValidator v(rx, 0);

    int pos = 0;
    if(v.validate(phone, pos) == QValidator::Acceptable)
        return true;
    else
        return false;
}



void MainWindow::on_send_button_clicked()
{

    QString name_string = ui->name_input->text();
    QString surname_string = ui->surname_input->text();
    QString email_string = ui->email_input->text();
    QString phone_string = ui->phone_input->text();

    bool correct_name = verifyName(name_string);
    bool correct_surname = verifyName(surname_string);
    bool correct_email = verifyEmail(email_string);
    bool correct_phone = verifyPhone(phone_string);

    if(correct_name)
        ui->name_err_label->setText("");
    else
        ui->name_err_label->setText("Name can contain only letters");

    if(correct_surname)
        ui->surname_err_label->setText("");
    else
        ui->surname_err_label->setText("Surname can contain only letters");

    if(correct_email)
        ui->email_err_label->setText("");
    else
        ui->email_err_label->setText("Email example: test@gmail.com");

    if(correct_phone)
        ui->phone_err_label->setText("");
    else
        ui->phone_err_label->setText("Phone example: 21234567");

    if(correct_name && correct_surname && correct_phone && correct_email)
    {
        QString exit_message = "Forma veiksmigi aizpildita!\nVards :" + name_string + "\nUzvards: " + surname_string + "\nTelefons: " + phone_string + "\nEpasts: " + email_string;
        QMessageBox successBox;
        successBox.setWindowTitle("Paldies!");
        successBox.setIcon(QMessageBox::Information);
        successBox.setText(exit_message);
        successBox.setStandardButtons(QMessageBox::Close);
        successBox.exec();
        QApplication::quit();
    }
}


