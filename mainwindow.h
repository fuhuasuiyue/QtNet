#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkConfigurationManager>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void netChange(bool isOnline);
    void netComplete();
private:
    Ui::MainWindow *ui;
    QNetworkConfigurationManager *m_netManager;
};

#endif // MAINWINDOW_H
