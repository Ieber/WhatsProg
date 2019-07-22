/********************************************************************************
** Form generated from reading UI file 'whatsprogmain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHATSPROGMAIN_H
#define UI_WHATSPROGMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WhatsProgMain
{
public:
    QAction *actionNovo;
    QAction *actionConectar;
    QAction *actionDesconectar;
    QAction *actionTrocar_senha;
    QAction *actionSair;
    QAction *actionNova_conversa;
    QAction *actionRemover_conversa;
    QAction *actionApagar_mensagens;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelConversas;
    QTableView *tableViewConversas;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelMensagens;
    QTableView *tableViewMensagens;
    QLabel *labelMensagem;
    QLineEdit *lineEditMensagem;
    QMenuBar *menuBar;
    QMenu *menuUsu_rio;
    QMenu *menuConversa;
    QMenu *menuMensagens;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WhatsProgMain)
    {
        if (WhatsProgMain->objectName().isEmpty())
            WhatsProgMain->setObjectName(QString::fromUtf8("WhatsProgMain"));
        WhatsProgMain->resize(673, 353);
        actionNovo = new QAction(WhatsProgMain);
        actionNovo->setObjectName(QString::fromUtf8("actionNovo"));
        actionConectar = new QAction(WhatsProgMain);
        actionConectar->setObjectName(QString::fromUtf8("actionConectar"));
        actionDesconectar = new QAction(WhatsProgMain);
        actionDesconectar->setObjectName(QString::fromUtf8("actionDesconectar"));
        actionTrocar_senha = new QAction(WhatsProgMain);
        actionTrocar_senha->setObjectName(QString::fromUtf8("actionTrocar_senha"));
        actionSair = new QAction(WhatsProgMain);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionNova_conversa = new QAction(WhatsProgMain);
        actionNova_conversa->setObjectName(QString::fromUtf8("actionNova_conversa"));
        actionRemover_conversa = new QAction(WhatsProgMain);
        actionRemover_conversa->setObjectName(QString::fromUtf8("actionRemover_conversa"));
        actionApagar_mensagens = new QAction(WhatsProgMain);
        actionApagar_mensagens->setObjectName(QString::fromUtf8("actionApagar_mensagens"));
        centralWidget = new QWidget(WhatsProgMain);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelConversas = new QLabel(centralWidget);
        labelConversas->setObjectName(QString::fromUtf8("labelConversas"));
        labelConversas->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelConversas);

        tableViewConversas = new QTableView(centralWidget);
        tableViewConversas->setObjectName(QString::fromUtf8("tableViewConversas"));

        verticalLayout->addWidget(tableViewConversas);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelMensagens = new QLabel(centralWidget);
        labelMensagens->setObjectName(QString::fromUtf8("labelMensagens"));
        labelMensagens->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelMensagens);

        tableViewMensagens = new QTableView(centralWidget);
        tableViewMensagens->setObjectName(QString::fromUtf8("tableViewMensagens"));

        verticalLayout_2->addWidget(tableViewMensagens);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        labelMensagem = new QLabel(centralWidget);
        labelMensagem->setObjectName(QString::fromUtf8("labelMensagem"));

        gridLayout->addWidget(labelMensagem, 1, 0, 1, 1);

        lineEditMensagem = new QLineEdit(centralWidget);
        lineEditMensagem->setObjectName(QString::fromUtf8("lineEditMensagem"));

        gridLayout->addWidget(lineEditMensagem, 1, 1, 1, 2);

        WhatsProgMain->setCentralWidget(centralWidget);
        labelMensagem->raise();
        lineEditMensagem->raise();
        menuBar = new QMenuBar(WhatsProgMain);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 673, 21));
        menuUsu_rio = new QMenu(menuBar);
        menuUsu_rio->setObjectName(QString::fromUtf8("menuUsu_rio"));
        menuConversa = new QMenu(menuBar);
        menuConversa->setObjectName(QString::fromUtf8("menuConversa"));
        menuMensagens = new QMenu(menuBar);
        menuMensagens->setObjectName(QString::fromUtf8("menuMensagens"));
        WhatsProgMain->setMenuBar(menuBar);
        statusBar = new QStatusBar(WhatsProgMain);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WhatsProgMain->setStatusBar(statusBar);

        menuBar->addAction(menuUsu_rio->menuAction());
        menuBar->addAction(menuConversa->menuAction());
        menuBar->addAction(menuMensagens->menuAction());
        menuUsu_rio->addAction(actionNovo);
        menuUsu_rio->addAction(actionConectar);
        menuUsu_rio->addAction(actionDesconectar);
        menuUsu_rio->addSeparator();
        menuUsu_rio->addAction(actionSair);
        menuConversa->addAction(actionNova_conversa);
        menuConversa->addAction(actionRemover_conversa);
        menuMensagens->addAction(actionApagar_mensagens);

        retranslateUi(WhatsProgMain);

        QMetaObject::connectSlotsByName(WhatsProgMain);
    } // setupUi

    void retranslateUi(QMainWindow *WhatsProgMain)
    {
        WhatsProgMain->setWindowTitle(QApplication::translate("WhatsProgMain", "Mensageiro", nullptr));
        actionNovo->setText(QApplication::translate("WhatsProgMain", "Novo ...", nullptr));
        actionConectar->setText(QApplication::translate("WhatsProgMain", "Conectar ...", nullptr));
        actionDesconectar->setText(QApplication::translate("WhatsProgMain", "Desconectar", nullptr));
        actionTrocar_senha->setText(QApplication::translate("WhatsProgMain", "Trocar senha ...", nullptr));
        actionSair->setText(QApplication::translate("WhatsProgMain", "Sair", nullptr));
        actionNova_conversa->setText(QApplication::translate("WhatsProgMain", "Nova conversa ...", nullptr));
        actionRemover_conversa->setText(QApplication::translate("WhatsProgMain", "Remover conversa", nullptr));
        actionApagar_mensagens->setText(QApplication::translate("WhatsProgMain", "Apagar mensagens", nullptr));
        labelConversas->setText(QApplication::translate("WhatsProgMain", "CONVERSAS", nullptr));
        labelMensagens->setText(QApplication::translate("WhatsProgMain", "MENSAGENS", nullptr));
        labelMensagem->setText(QApplication::translate("WhatsProgMain", "Mensagem:", nullptr));
        menuUsu_rio->setTitle(QApplication::translate("WhatsProgMain", "Usu\303\241rio", nullptr));
        menuConversa->setTitle(QApplication::translate("WhatsProgMain", "Conversas", nullptr));
        menuMensagens->setTitle(QApplication::translate("WhatsProgMain", "Mensagens", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WhatsProgMain: public Ui_WhatsProgMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHATSPROGMAIN_H
