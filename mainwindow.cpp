#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QNetworkConfiguration>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_netManager = new QNetworkConfigurationManager(this);
    connect(m_netManager, SIGNAL(onlineStateChanged(bool)), this, SLOT(netChange(bool)));
    connect(m_netManager, SIGNAL(updateCompleted()), this, SLOT(netComplete()));
    qDebug() << "App is running!";
    QNetworkConfigurationManager mgr;
    QList<QNetworkConfiguration> activeConfigs = mgr.allConfigurations(QNetworkConfiguration::Active);
    if(activeConfigs.count() > 0)
    {
        qDebug() << "Active count: " << activeConfigs.count();
        for(int nIndex = 0; nIndex < activeConfigs.count(); nIndex++)
        {
            qDebug() << activeConfigs.at(nIndex).name();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::netChange(bool isOnline)
{
    if(isOnline)
    {
        qDebug() << "OnLine";
    }else{
        qDebug() << "OffLine";
    }

}

void MainWindow::netComplete()
{
    qDebug() << "Line net";
}
