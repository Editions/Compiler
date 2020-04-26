#include "mainwindow.h"
#include<QFileDialog>
#include<QTextStream>
#include "ui_mainwindow.h"
#include<fstream>
#include<globals.h>
using namespace std;
extern FILE* yyin;
QString sourcefile;
bool TokenAna;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    setPalette(QPalette(QColor(138,151,123)));

    QPalette pa = ui->textEdit->palette();
    pa.setColor(QPalette::Base,QColor(182,194,154));
    ui->textEdit->setPalette(pa);
    ui->textBrowser->setPalette(pa);
    ui->textBrowser_2->setPalette(pa);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run()
{
    lineno = 1;
    //TokenAna = true;
    QString path1 = qApp->applicationDirPath() + "\\textedit_input.txt";
    QFile* file1 = new QFile();
    file1->setFileName(path1);
    file1->open(QIODevice::WriteOnly);

    QString text = ui->textEdit->toPlainText();
    QTextStream outfile(file1);
    outfile << text ;
    file1->close();
    delete file1;

    QString path = qApp->applicationDirPath() + "\\result_of_token.txt";
    QString path2 = qApp->applicationDirPath()+"\\result_of_tree.txt";

    tokenlisting = fopen(path.toStdString().c_str(), "w");
    fd = fopen(path2.toStdString().c_str(), "w");
    yyin = fopen(path1.toStdString().c_str(), "r");

    TreeNode* root = parse();
    printtree(root, 0);
    fclose(tokenlisting);
    fclose(fd);
    yyin = nullptr;
    fd = nullptr;
    tokenlisting = nullptr;
    deletetree(root);

    QFile* file = new QFile();
    QFile* filew = new QFile();
    filew->setFileName(path2);
    file->setFileName(path);
    file->open(QFile::ReadOnly);
    filew->open(QFile::ReadOnly);
    QTextStream in(file);
    ui->textBrowser_2->setText((in.readAll()));
    QTextStream inn(filew);
    ui->textBrowser->setText((inn.readAll()));
    file->close();
    filew->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("选择文件"),"./", tr("All files(*.*)"));
    QFile* file1 = new QFile();
    file1->setFileName(filename);
    file1->open(QFile::ReadOnly);
    QTextStream in1(file1);
    ui->textEdit->setText((in1.readAll()));
    file1->close();
    delete file1;
}


void MainWindow::on_pushButton_clicked()
{
    run();
}
