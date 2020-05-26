//
// Created by septemberhx on 2020/5/26.
//

#ifndef DDE_TOP_PANEL_ACTIVEWINDOWCONTROLWIDGET_H
#define DDE_TOP_PANEL_ACTIVEWINDOWCONTROLWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QToolButton>
#include <com_deepin_dde_daemon_dock.h>

using DBusDock = com::deepin::dde::daemon::Dock;

class ActiveWindowControlWidget : public QWidget {

    Q_OBJECT

public:
    explicit ActiveWindowControlWidget(QWidget *parent = 0);

public slots:
    void activeWindowInfoChanged();

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    void setButtonsVisible(bool visible);

private slots:
    void maxButtonClicked();

private:
    QHBoxLayout *m_layout;
    QLabel *m_winTitleLabel;

    int currActiveWinId;
    QString currActiveWinTitle;

    QToolButton *closeButton;
    QToolButton *minButton;
    QToolButton *maxButton;

    DBusDock *m_appInter;
};


#endif //DDE_TOP_PANEL_ACTIVEWINDOWCONTROLWIDGET_H
