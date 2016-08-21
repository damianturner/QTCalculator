#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setAlignment(Qt::AlignRight);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
    std::string currText = ui->textEdit->toPlainText().toStdString();
    if(!currText.empty() && currText.at(currText.size() - 1) == '\n') {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.deletePreviousChar(); // trims empty line
        ui->textEdit->setTextCursor(cursor);
        parseLine();
    }
}

std::string parse(std::string input)
{
    TODO
    return "parsed" + input;
}

void MainWindow::parseLine() {
    std::string input = ui->textEdit->textCursor().block().text().toStdString();
    ui->textEdit->append(QString::fromStdString(parse(input)));
}

void MainWindow::on_enterButton_clicked()
{
    parseLine();
}

void MainWindow::on_addButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("+"));
}

void MainWindow::on_subButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("-"));
}

void MainWindow::on_multButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("*"));
}

void MainWindow::on_divButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("/"));
}

void MainWindow::on_clearButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_xButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("x"));
}

void MainWindow::on_sevenButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("7"));
}

void MainWindow::on_fourButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("4"));
}

void MainWindow::on_oneButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("1"));
}

void MainWindow::on_zeroButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("0"));
}

void MainWindow::on_diffButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("dx"));
}

void MainWindow::on_eightButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("8"));
}

void MainWindow::on_fiveButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("5"));
}

void MainWindow::on_twoButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("2"));
}

void MainWindow::on_negativeButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("(-1)*"));
}

void MainWindow::on_integrateButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("dx/dy"));
}

void MainWindow::on_nineButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("9"));
}

void MainWindow::on_sixButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("6"));
}

void MainWindow::on_threeButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString("3"));
}
