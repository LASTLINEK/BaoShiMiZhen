/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QWidget *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QString::fromUtf8("Help"));
        Help->resize(393, 260);
        Help->setContextMenuPolicy(Qt::CustomContextMenu);
        label = new QLabel(Help);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 391, 261));
        label->setPixmap(QPixmap(QString::fromUtf8(":/back/help.jpg")));
        textEdit = new QTextEdit(Help);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 20, 291, 221));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        textEdit->setFont(font);
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setReadOnly(true);
        textEdit->setOverwriteMode(false);
        textEdit->setAcceptRichText(true);
        textEdit->setCursorWidth(1);

        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QWidget *Help)
    {
        Help->setWindowTitle(QCoreApplication::translate("Help", " \345\270\256\345\212\251", nullptr));
        label->setText(QString());
        textEdit->setHtml(QCoreApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">\346\270\270\346\210\217\345\270\256\345\212\251\357\274\232</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">1.\344\272\244\346\215\242</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">\347\216\251\345\256\266\351\200\211\344\270"
                        "\255\347\233\270\351\202\273\347\232\204\344\270\244\344\270\252\345\256\235\347\237\263\344\275\215\347\275\256\350\277\233\350\241\214\344\272\244\346\215\242\357\274\214\345\246\202\346\236\234\344\272\244\346\215\242\346\210\220\345\212\237\345\210\231\346\266\210\351\231\244\345\256\235\347\237\263\357\274\214\345\220\246\345\210\231\345\217\226\346\266\210\344\275\215\347\275\256\344\272\244\346\215\242</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">2.\346\266\210\351\231\244</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">\347\216\251\345\256\266\351\200\211\346\213\251\344\270\244\344\270\252\345\256\235\347\237\263\350\277\233\350\241\214\344\275\215\347\275\256\344\272\244\346\215\242\357\274\214\344\272\244\346\215"
                        "\242\345\220\216\345\246\202\346\236\234\346\250\252\346\216\222\346\210\226\347\253\226\346\216\222\346\234\211\344\270\211\344\270\252\346\210\226\344\270\211\344\270\252\344\273\245\344\270\212\347\232\204\347\233\270\345\220\214\345\256\235\347\237\263\357\274\214\345\210\231\346\266\210\351\231\244\350\277\231\344\272\233\347\233\270\345\220\214\345\256\235\347\237\263\357\274\214\346\266\210\351\231\244\345\220\216\344\270\213\350\220\275\351\232\217\346\234\272\345\256\235\347\237\263\357\274\214\345\220\246\345\210\231\344\270\244\344\270\252\345\256\235\347\237\263\346\215\242\345\233\236\345\216\237\346\235\245\347\232\204\344\275\215\347\275\256\343\200\202</span></p></body></html>", nullptr));
        textEdit->setProperty("markdown", QVariant(QCoreApplication::translate("Help", "**\346\270\270\346\210\217\345\270\256\345\212\251\357\274\232**\n"
"\n"
"**1.\344\272\244\346\215\242**\n"
"\n"
"**\347\216\251\345\256\266\351\200\211\344\270\255\347\233\270\351\202\273\347\232\204\344\270\244\344\270\252\345\256\235\347\237\263\344\275\215\347\275\256\350\277\233\350\241\214\344\272\244\346\215\242\357\274\214\345\246\202\346\236\234\344\272\244\346\215\242\346\210\220\345\212\237\345\210\231\346\266\210\351\231\244\345\256\235\347\237\263\357\274\214\345\220\246\345\210\231\345\217\226\346\266\210\344\275\215\347\275\256\344\272\244\346\215\242**\n"
"\n"
"**2.\346\266\210\351\231\244**\n"
"\n"
"**\347\216\251\345\256\266\351\200\211\346\213\251\344\270\244\344\270\252\345\256\235\347\237\263\350\277\233\350\241\214\344\275\215\347\275\256\344\272\244\346\215\242\357\274\214\344\272\244\346\215\242\345\220\216\345\246\202\346\236\234\346\250\252\346\216\222\346\210\226\347\253\226\346\216\222\346\234\211\344\270\211\344\270\252\346\210\226\344\270\211\344\270\252\344\273\245\344\270\212\347"
                        "\232\204\347\233\270\345\220\214\345\256\235\347\237\263\357\274\214\345\210\231\346\266\210\351\231\244\350\277\231\344\272\233\347\233\270\345\220\214\345\256\235\347\237\263\357\274\214\346\266\210\351\231\244\345\220\216\344\270\213\350\220\275\351\232\217\346\234\272\345\256\235\347\237\263\357\274\214\345\220\246\345\210\231\344\270\244\344\270\252\345\256\235\347\237\263\346\215\242\345\233\236\345\216\237\346\235\245\347\232\204\344\275\215\347\275\256\343\200\202**\n"
"\n"
"", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
