#include "notepadwindow.h"

NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{


    QPixmap openpix(":/Resources/open.png");
    QPixmap copypix(":/Resources/copy.png");
    QPixmap cutpix(":/Resources/cut.png");
    QPixmap pastepix(":/Resources/paste.png");
    QPixmap savepix(":/Resources/save.png");
    QPixmap redopix(":/Resources/redo.png");
    QPixmap undopix(":/Resources/undo.png");
    QPixmap boldpix(":/Resources/bold.png");
    QPixmap underlinepix(":/Resources/underline.png");
    QPixmap italicpix(":/Resources/italic.png");

    italicBool_ = true;


    toolBar_=addToolBar(tr("Edit"));
    //Establecemos el tamaño inicial de la ventana
    this->setGeometry(30, 30, 800, 600);

    //Establecemos el título de la ventana
    this->setWindowTitle(tr("Super editor de texto"));

    //Inicializamos los menús
    mainMenu_ = new QMenuBar(this);

    mnuArchivo_ = new QMenu(tr("&Archivo"), this);
    mainMenu_->addMenu(mnuArchivo_);

    actArchivoAbrir_ = new QAction(tr("&Abrir"), this);
    actToolAbrir_ = new QAction(QIcon(openpix), "");
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    mnuArchivo_->addAction(actArchivoAbrir_);
    toolBar_->addAction(actToolAbrir_);



    actArchivoGuardar_ = new QAction(tr("&Guardar"), this);
    actToolGuardar_ = new QAction(QIcon(savepix), "");
    actArchivoGuardar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    mnuArchivo_->addAction(actArchivoGuardar_);
    toolBar_->addAction(actToolGuardar_);

    actArchivoSalir_ = new QAction(tr("&Salir"), this);
    mnuArchivo_->addAction(actArchivoSalir_);

    mnuEditar_ = new QMenu(tr("&Editar"), this);
    mainMenu_->addMenu(mnuEditar_);

    actEditarCopiar_ = new QAction(tr("&Copiar"), this);
    actToolCopiar_ = new QAction(QIcon(copypix), "");
    actEditarCopiar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    mnuEditar_->addAction(actEditarCopiar_);
    toolBar_->addAction(actToolCopiar_);

    actEditarPegar_ = new QAction(tr("&Pegar"), this);
    actToolPegar_ = new QAction(QIcon(pastepix), "");
    actEditarPegar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    mnuEditar_->addAction(actEditarPegar_);
    toolBar_->addAction(actToolPegar_);

    actEditarCortar_ = new QAction(tr("&Cortar"), this);
    actToolCortar_ = new QAction(QIcon(cutpix), "");
    actEditarCortar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    mnuEditar_->addAction(actEditarCortar_);
    toolBar_->addAction(actToolCortar_);

    actEditarDeshacer_ = new QAction(tr("&Deshacer"), this);
    actToolDeshacer_ = new QAction(QIcon(undopix), "");
    actEditarDeshacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    mnuEditar_->addAction(actEditarDeshacer_);
    toolBar_->addAction(actToolDeshacer_);

    actEditarRehacer_ = new QAction(tr("&Rehacer"), this);
    actToolRehacer_ = new QAction(QIcon(redopix), "");
    actEditarRehacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    mnuEditar_->addAction(actEditarRehacer_);
    toolBar_->addAction(actToolRehacer_);

    actToolBold_ = new QAction(QIcon(boldpix), "");
    actToolBold_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
    toolBar_->addAction(actToolBold_);

    actToolUnderline_ = new QAction(QIcon(underlinepix), "");
    toolBar_->addAction(actToolUnderline_);

    actToolItalic_ = new QAction(QIcon(italicpix), "");
    toolBar_->addAction(actToolItalic_);

    mnuFormato_ = new QMenu(tr("&Formato"), this);
    mainMenu_->addMenu(mnuFormato_);

    actFormatoFuente_ = new QAction(tr("&Fuente"), this);
    mnuFormato_->addAction(actFormatoFuente_);

    //Agregamos la barra de menú a la ventana
    this->setMenuBar(mainMenu_);

    //Inicializamos el editor de texto
    txtEditor_ = new QTextEdit(this);

    //Conectamos las acciones de los menús con nuestros slots
    connect(actArchivoAbrir_,   SIGNAL(triggered()), this,          SLOT(alAbrir()));
    connect(actToolAbrir_,      SIGNAL(triggered()), this,          SLOT(alAbrir()));
    connect(actArchivoGuardar_, SIGNAL(triggered()), this,          SLOT(alGuardar()));
    connect(actToolGuardar_,    SIGNAL(triggered()), this,          SLOT(alGuardar()));
    connect(actArchivoSalir_,   SIGNAL(triggered()), this,          SLOT(alSalir()));
    connect(actEditarCopiar_,   SIGNAL(triggered()), txtEditor_,    SLOT(copy()));
    connect(actToolCopiar_,     SIGNAL(triggered()), txtEditor_,    SLOT(copy()));
    connect(actEditarPegar_,    SIGNAL(triggered()), txtEditor_,    SLOT(paste()));
    connect(actToolPegar_,      SIGNAL(triggered()), txtEditor_,    SLOT(paste()));
    connect(actEditarCortar_,   SIGNAL(triggered()), txtEditor_,    SLOT(cut()));
    connect(actToolCortar_,     SIGNAL(triggered()), txtEditor_,    SLOT(cut()));
    connect(actEditarDeshacer_, SIGNAL(triggered()), txtEditor_,    SLOT(undo()));
    connect(actToolDeshacer_,   SIGNAL(triggered()), txtEditor_,    SLOT(undo()));
    connect(actEditarRehacer_,  SIGNAL(triggered()), txtEditor_,    SLOT(redo()));
    connect(actToolRehacer_,    SIGNAL(triggered()), txtEditor_,    SLOT(redo()));
    connect(actFormatoFuente_,  SIGNAL(triggered()), this,          SLOT(alFuente()));
    connect(actToolBold_,       SIGNAL(triggered()), this,          SLOT(negrita()));
    connect(actToolUnderline_,  SIGNAL(triggered()), this,          SLOT(subrayado()));
    connect(actToolItalic_,     SIGNAL(triggered()), this,          SLOT(cursiva()));


    //Agregamos el editor de texto a la ventana
    this->setCentralWidget(txtEditor_);
}

NotepadWindow::~NotepadWindow()
{
    //Liberamos los recursos
    mainMenu_->deleteLater();
    actArchivoAbrir_->deleteLater();
    actArchivoGuardar_->deleteLater();
    mnuArchivo_->deleteLater();
    actEditarCopiar_->deleteLater();
    actEditarPegar_->deleteLater();
    mnuEditar_->deleteLater();
    actFormatoFuente_->deleteLater();
    mnuFormato_->deleteLater();
    txtEditor_->deleteLater();
}

void NotepadWindow::alAbrir()
{
    //Mostramos un dialogo de apertura de ficheros y almacenamos la selección (ruta) en una variable
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getOpenFileName(this,
                                                 tr("Abrir archivo de texto plano"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        archivo.setFileName(nombreArchivo);
        if (archivo.open(QFile::ReadOnly)) {
            //Si se pudo abrir el archivo, lo leemos y colocamos su contenido en nuestro editor
            txtEditor_->setHtml(archivo.readAll());
            //Se cierra el fichero
            archivo.close();
        }
    }
}

void NotepadWindow::alGuardar()
{
    //Mostramos un dialogo de guardado de ficheros y almacenamos la selección (ruta) en una variable
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getSaveFileName(this,
                                                 tr("Guardar archivo de texto plano"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        archivo.setFileName(nombreArchivo + ".txt");
        if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
            //Si se pudo abrir el archivo, escribimos el contenido del editor
            archivo.write(txtEditor_->toHtml().toUtf8());
            //Se cierra el fichero
            archivo.close();
        }
    }
}

void NotepadWindow::alSalir(){

    QApplication::quit();
}

void NotepadWindow::alFuente()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, txtEditor_->font(), this);
    if (ok) {
        // Si el usuario hizo click en OK, se establece la fuente seleccionada
        txtEditor_->setFont(font);
    }
}

void NotepadWindow::negrita(){

    QFont font(txtEditor_->font());
    font.setBold(!font.bold());
    txtEditor_->setFont(font);

}
void NotepadWindow::subrayado(){

    QFont font(txtEditor_->font());
    font.setUnderline(!font.underline());
    txtEditor_->setFont(font);

}

void NotepadWindow::cursiva(){


    QTextCursor cursor = txtEditor_->textCursor();
    QTextCharFormat format;

    QFont font1(cursor.selectedText());
    format = cursor.charFormat();

    format.setFontItalic(italicBool_);
    italicBool_ = !italicBool_;
    cursor.mergeCharFormat(format);

   // format.setFont(QFont(cursor.currentText());
/*
    QFont font(txtEditor_->font());
    font.setItalic(!font.italic());
    txtEditor_->setFont(font);*/

}
