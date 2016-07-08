/* 
 * File:   TouchDialog.h
 * Author: Rashad Amirjanov
 *
 * Created on May 7, 2009, 4:43 PM
 */

#ifndef _TOUCHSCREENKEYBOARD_H
#define	_TOUCHSCREENKEYBOARD_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtGui/QKeyEvent>
#include <QtCore/QString>

#include "../qcomps_global.h"

#define MAX_LETTER_KEYS   40
#define MAX_NUMBER_KEYS   15

#define KY_LINE         "[newline]"
#define KY_CAPS_LOCK    "[capslock]"
#define KY_SHIFT        "[shift]"

class QCOMPS_EXPORT TouchScreenKeyboard : public QDialog {
    Q_OBJECT
public:
    TouchScreenKeyboard(QWidget *parent = 0);
    ~TouchScreenKeyboard();

    static void initKeyboard();
    static void showKeyboard(QWidget *parent);
    static void hideKeyboard();
public slots:
    void keysClicked();
    void btnLanguageClicked();
    void keyCapsLockClicked();
private:
    void initKeyboardButtons();
    void initKeyboardLettersRu();
    void initKeyboardLettersEng();
    void initKeyboardNumbers();
    void showEvent(QShowEvent *);
    QPushButton *keyLetters[MAX_LETTER_KEYS];
    QPushButton *keyNumbers[MAX_NUMBER_KEYS];
    QVector<QString> chars;
    QVector<QString> numbers;
    QPushButton *keyCapsLock, *keySpace, *keyBackSpace, *btnLanguage;
    static TouchScreenKeyboard *keyboard;
};

class QCOMPS_EXPORT TouchDialog : public QDialog {
public:

    TouchDialog(QWidget * parent = 0) : QDialog(parent) {

    }

    virtual ~TouchDialog() {

    }
protected:

    void showEvent(QShowEvent *) {
        TouchScreenKeyboard::showKeyboard(this);
    }

    void closeEvent(QCloseEvent *) {
        TouchScreenKeyboard::hideKeyboard();
    }
};

#endif	/* _TOUCHSCREENKEYBOARD_H */

