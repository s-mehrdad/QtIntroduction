﻿
// ===========================================================================
/// <summary>
/// mainwindow.h
/// QtIntroduction
/// created by Mehrdad Soleimanimajd on 10.09.2019
/// </summary>
/// <created>ʆϒʅ, 10.09.2019</created>
/// <changed>ʆϒʅ, 27.06.2023</changed>
// ===========================================================================

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <qapplication.h>
#include <qwidget.h>
#include <qmainwindow.h>
#include <qmenu.h>
#include <qboxlayout.h>

#include "style.h"
#include "screenshot.h"


class MainWindow : public QMainWindow
{
    friend class AppStyle;

    Q_OBJECT
private:

    // custom context menu implementation need:
    // reimplementation is needed to receive the context menu events for the created main window.
    //#ifndef QT_NO_CONTEXTMENU
    //  void contextMenuEvent ( QContextMenuEvent* ) override;
    //#endif // QT_NO_CONTEXTMENU

    AppStyle* appStyle; // application theme

    // private slots: to respond to the user actions on the menu entries,
    // most of which display the action's path in the central main window widget.
private slots:
    void themeOne ( void ); // first theme
    void screenShot ( void );

private:
    QMenu* menuFile; // menu widget
    QAction* actionScreenShot; // abstract user interface action, insertable into widgets
    QMenu* menuView;
    QAction* actionTheme;
    //QActionGroup* alignmentGroup; // to group the actions

    ScreenShot* windowScreenShot; // screen shot window wrapper

    void createActions ( void ); // main window menu actions creator
    void createMenus ( void ); // main window menu creator

public:
    MainWindow ();
    ~MainWindow ( void );
    void setStyle ( unsigned char ); // set the style
};


#endif // MAINWINDOW_H
