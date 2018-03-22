#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QListView>
#include <QDebug>
#include <QPalette>
#include <QWidget>
#include <QHeaderView>
#include <QIcon>
#include <QPushButton>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel;
    QImage image(":/TIM图片20180319172005.png");
    QIcon icon(QPixmap::fromImage(image));

    QStandardItem *item0 = new QStandardItem("01 PRO Capture Quad HDMI");
    item0->setIcon(icon);
    model->setItem(0, item0);

    QStandardItem *item1 = new QStandardItem("15 PRO Capture DVI 4K");
    item1->setIcon(icon);
    model->setItem(1, item1);

    QStandardItem *item2 = new QStandardItem("12 PRO Capture SDK PLUS");
    item2->setIcon(icon);
    //model->setItem(2, item2);
    model->appendRow(item2);

    //model->insertColumns(0, 1);

    QTableView *tableview = new QTableView;
    tableview->setFocusPolicy(Qt::NoFocus);

    tableview->setStyleSheet("QTableView{"
                             "color:#dcdcdc;"
                             "gridline-color:#252525;"
                             "}"
                             "QTableView:item{"
                             "padding-left: px;"
                             "background: #343434;"
                             "padding: 10px;"
                             "}"
                             "QTableView:item:hover{"
                             "color: #dcdcdc;"
                             "background: #2b3d4a;"
                             "}"
                             "QTableView:item:selected{"
                             "background: #314553;"
                             "color: #ffffff;"
                             "}"
                             "QTableView:indicator {width: 20px;height: 20px;}"
                             "QHeaderView{"
                             ""
                             "}"
//                             "QHeaderView:section{"
//                             "background: #343434;"
//                             "width: 50px;"
//                             "}"
                             "userIcon{ background:url() left center no-repeat; padding-left:16px;}");
    //tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //tableview->setGridStyle(Qt::PenStyle::NoPen);

    tableview->horizontalHeader()->hide();
    tableview->verticalHeader()->hide();
    tableview->setModel(model);
    for(int i = 0; i < model->rowCount(); ++i){
        tableview->setRowHeight(i, 50);}
    for(int i = 0; i < model->columnCount(); ++i){
        tableview->setColumnWidth(i, 307);}
    tableview->setIconSize(QSize(50, 50));

//    model->insertColumns(1, 1);
//    for(int i = 0; i < model->rowCount(); ++i)
//    {
//        QPushButton *m_button = new QPushButton("download");
//        m_button->setText("Button");
//        m_button->setProperty("row", i);
//        m_button->setProperty("fileName", QString("Section%1").arg(i));
//        connect(m_button, SIGNAL(clicked(bool)), this, SLOT(ClickDownloadButton()));
//        tableview->setIndexWidget(model->index(model->rowCount() - 1, 3), m_button);
//    }

    setCentralWidget(tableview);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ClickDownloadButton()
{
    QPushButton *btn = (QPushButton *)sender();
    QString row = btn->property("row").toString();
    qDebug() << "row";
}
