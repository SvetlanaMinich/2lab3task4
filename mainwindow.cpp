#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
          ui->tableWidget->setColumnCount(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Vector<int> v(1);

void MainWindow::on_capacity_clicked()
{
    QString cap = QString::number(v.capacity());
    QMessageBox::information(this,"Capacity",cap);
}


void MainWindow::on_size_clicked()
{
    QString siz = QString::number(v.size());
    QMessageBox::information(this,"Size",siz);
}


void MainWindow::on_add_el_clicked()
{
    QString add = ui->lineEdit->text();
    if(add!=""){
        v.push_back(add.toInt());
        QTableWidgetItem *tbl=new QTableWidgetItem(add);
        if(ui->tableWidget->columnCount()==1){
            ui->tableWidget->setItem(0,0,tbl);
            ui->tableWidget->insertColumn(1);
        }
        else{
            qDebug()<<v[v.size()-1];
            ui->tableWidget->setItem(0,ui->tableWidget->columnCount()-1,tbl);
            ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
        }
        ui->lineEdit->clear();
    }
}


void MainWindow::on_del_el_clicked()
{
    if(ui->tableWidget->columnCount()!=1){
        v.pop_back();
        if(ui->tableWidget->columnCount()==1){
            ui->tableWidget->removeColumn(ui->tableWidget->columnCount()-1);
        }
        else{
            ui->tableWidget->removeColumn(ui->tableWidget->columnCount()-2);
        }
    }
}


void MainWindow::on_clear_clicked()
{
    v.clear();
    ui->tableWidget->clear();
    for(int i=ui->tableWidget->columnCount()-1; i>=1; i--){
        ui->tableWidget->removeColumn(i);
    }
}


void MainWindow::on_insert_clicked()
{
    if(ui->num_insert->text()!="" && ui->val_insert->text()!=""){
        QString num_str = ui->num_insert->text();
        QString val_str = ui->val_insert->text();
        int num = num_str.toInt();
        int val = val_str.toInt();
        if(num<v.size()){
            v.insert(num,val);
            ui->tableWidget->insertColumn(num);
            QTableWidgetItem *tbl=new QTableWidgetItem(val_str);
            ui->tableWidget->setItem(0,num,tbl);

        }
    }
}


void MainWindow::on_empty_clicked()
{
    if(v.empty()){
        QMessageBox::information(this,"Empty?","yes");
    }
    else{
        QMessageBox::information(this,"Empty?","no");
    }
}


void MainWindow::on_erase_clicked()
{
    QString num_str = ui->num_erase->text();
    if(num_str!=""){
        int num = num_str.toInt();
        if(num>0 && num<v.size()){
            v.erase(num);
            ui->tableWidget->removeColumn(num);
        }
    }
}

