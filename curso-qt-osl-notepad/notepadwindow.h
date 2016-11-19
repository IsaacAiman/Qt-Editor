#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
//Incluimos librerias necesarias
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QFontDialog>
#include <QClipboard>
#include <QKeySequence>
#include <QApplication>
#include <QToolBar>
#include <QIcon>
#include <QPixmap>
#include <QTextEdit>
#include <QFont>
#include <QDebug>
#include <QCursor>
#include <QTextDocumentFragment>


class NotepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    NotepadWindow(QWidget *parent = 0);
    ~NotepadWindow();

private slots:
    void alAbrir();
    void alGuardar();
    void alFuente();
    void alSalir();
    void negrita();
    void subrayado();
    void cursiva();

private:

    QToolBar*       toolBar_;
    QMenuBar*       mainMenu_;
    QMenu*          mnuArchivo_;
    QAction*        actArchivoAbrir_;
    QAction*        actToolAbrir_;
    QAction*        actArchivoSalir_;
    QAction*        actArchivoGuardar_;
    QAction*        actToolGuardar_;
    QMenu*          mnuFormato_;
    QAction*        actFormatoFuente_;
    QMenu*          mnuEditar_;
    QAction*        actEditarCopiar_;
    QAction*        actToolCopiar_;
    QAction*        actEditarPegar_;
    QAction*        actToolPegar_;
    QAction*        actEditarCortar_;
    QAction*        actToolCortar_;
    QAction*        actEditarDeshacer_;
    QAction*        actToolDeshacer_;
    QAction*        actEditarRehacer_;
    QAction*        actToolRehacer_;
    QAction*        actToolBold_;
    QAction*        actToolUnderline_;
    QAction*        actToolItalic_;
    QTextEdit*      txtEditor_;
    QClipboard *    portapapeles_;
    bool            italicBool_;

};

#endif // NOTEPADWINDOW_H
